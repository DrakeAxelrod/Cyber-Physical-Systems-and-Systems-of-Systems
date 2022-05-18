#include "steering-angle-generator.hpp"
#include <limits>
#include <fstream>
const std::string hsv_window_name = "HSVView";
// Matrix to store points of cones in HSV filter.
std::vector<std::vector<cv::Point>> blue_points;
std::vector<std::vector<cv::Point>> yellow_points;

// upper and lower bounds of the yellow and blue cones (hsv)
Bound<cv::Scalar> yellow(cv::Scalar(17, 89, 128), cv::Scalar(35, 175, 216));
Bound<cv::Scalar> blue(cv::Scalar(70, 43, 34), cv::Scalar(120, 255, 255));

HSVBounds hsv_bounds = HSVBounds(17, 35, 89, 175, 128, 216);
// nose of the car
cv::Point car;
double steering_angle = 0;
double threshold = 335;
bool blue_is_left;
Images imgs = Images();
// color blue as a scalar value BGR (blue, green, red)
cv::Scalar color_blue(255, 0, 0);
// color yellow as a scalar value BGR (blue, green, red)
cv::Scalar color_yellow(0, 255, 255);
// Constants
const double CLOCKWISE_LEFT = 0.1171807038;
const double CLOCKWISE_RIGHT = -0.1356987459;
const double COUNTERCLOCKWISE_LEFT = 0.1203680391;
const double COUNTERCLOCKWISE_RIGHT = -0.1308372994;
const double MEDIAN_TURN_VALUE = 0.14102119705;
const double MAX_STEERING_VALUE = 0.290888;
const int NOISE_THRESHOLD = 0;

// ================= verifier code ====================== //
std::vector<std::string> csv_lines = std::vector<std::string>();
std::string output;
void toCSV(std::string filepath)
{
  std::ofstream myfile;
  myfile.open(filepath);
  // myfile << "actualSteering" << ";" << "computedSteering" << std::endl;
  for (int i = 0; i < csv_lines.size(); i++)
  {
    myfile << csv_lines[i] << std::endl;
  }
  myfile.close();
}
// ================= verifier code ====================== //

class Cone
{
public:
  cv::Rect box;
  cv::Scalar color;
  // constructor
  Cone(cv::Rect box, cv::Scalar color)
  {
    this->box = box;
    this->color = color;
  }
  // getters
  cv::Rect getBox() { return box; }
  cv::Scalar getColor() { return color; }
  // get the angrom from the center of the box to the center of a point
  double getAngleFrom(cv::Point point)
  {
    double angle = atan2(point.y - box.y - box.height / 2,
                         point.x - box.x - box.width / 2);
    return angle;
  }
  // get the distance from the center of the box to the center of a point
  double getDistanceFrom(cv::Point point)
  {
    return sqrt(pow(point.x - box.x - box.width / 2, 2) +
                pow(point.y - box.y - box.height / 2, 2));
  }
  // get the center of the box
  cv::Point getCenter()
  {
    return cv::Point(box.x + box.width / 2, box.y + box.height / 2);
  }
};

bool detectBlueCones(cv::Mat hsv_frame)
{
  cv::findContours(hsv_frame, blue_points, cv::RETR_EXTERNAL,
                   cv::CHAIN_APPROX_SIMPLE, cv::Point());
  return blue_points.size() > 0 ? true : false;
}

bool detectYellowCones(cv::Mat hsv_frame)
{
  cv::findContours(hsv_frame, yellow_points, cv::RETR_EXTERNAL,
                   cv::CHAIN_APPROX_SIMPLE, cv::Point());
  return yellow_points.size() > 0 ? true : false;
}

Cone getCone(cv::Mat cropped_frame, cv::Mat hsv_frame, cv::Scalar color,
             std::vector<std::vector<cv::Point>> matrix)
{
  // create a bounding box
  cv::Rect box(cv::Point(0, 0), cv::Size(0, 0));
  // extract the bounding box of the cone from the provided matrix
  // cv::findContours(hsv_frame, matrix, cv::RETR_EXTERNAL,
  // cv::CHAIN_APPROX_SIMPLE, cv::Point()); draw box
  cv::rectangle(cropped_frame, box, color, 2);
  for (auto &contour : matrix)
  {
    cv::Rect tmp = cv::boundingRect(contour);
    if (tmp.area() > NOISE_THRESHOLD)
    {
      // using the matrix build a bounding box
      cv::Rect tmp = cv::boundingRect(contour);
      cv::Point tmp_center =
          cv::Point(tmp.x + tmp.width / 2, tmp.y + tmp.height / 2);
      // draw the bounding box
      cv::rectangle(cropped_frame, tmp, color, 2);
      // draw the center of the bounding box
      cv::circle(cropped_frame, tmp_center, 5, color, -1);
      if (box.width > 0)
      {
        // get the box center
        cv::Point center =
            cv::Point(box.x + box.width / 2, box.y + box.height / 2);
        // draw the bounding box
        cv::rectangle(cropped_frame, box, color, 2);
        // // draw the center of the bounding box
        cv::circle(cropped_frame, center, 5, color, -1);
        // draw a line between previous center and current center
        cv::line(cropped_frame, center, tmp_center, color, 2);
      }
      box = tmp;
    }
  }
  return Cone(box, color);
}


// calculate the give steering adjustment based on the
// distance of the blue & yellow cones from the center of the car
double getSteeringAngle(opendlv::proxy::MagneticFieldReading mfr,
                        opendlv::proxy::AccelerationReading ar,
                        opendlv::proxy::AngularVelocityReading vel,
                        opendlv::logic::sensation::Geolocation gr)
{
  double blue_correction = 0;
  double yellow_correction = 0;
  // segment blue
  cv::inRange(imgs.img_hsv, blue.low, blue.high, imgs.fr_hsv);
  // check for blue
  bool blue_detected = detectBlueCones(imgs.fr_hsv);
  // get the blue cone
  Cone blue_cone =
      getCone(imgs.fr_cropped, imgs.fr_hsv, color_blue, blue_points);
  // segment yellow
  cv::inRange(imgs.img_hsv, yellow.low, yellow.high, imgs.fr_hsv);
  // check for yellow
  bool yellow_detected = detectYellowCones(imgs.fr_hsv);
  // get the yellow cone
  Cone yellow_cone =
      getCone(imgs.fr_cropped, imgs.fr_hsv, color_yellow, yellow_points);
  // get the angle of the yellow cone from the car in radians
  double yellow_angle_from_car = yellow_cone.getAngleFrom(car);
  // get the angle of the blue cone from the car in radians
  double blue_angle_from_car = blue_cone.getAngleFrom(car);
  // get the distance of the blue cone from the center of the car
  double blue_distance = blue_cone.getDistanceFrom(car);
  // get the distance of the yellow cone from the center of the car
  double yellow_distance = yellow_cone.getDistanceFrom(car);
  // get the magnentic field readings of the car
  double magnetic_field_x = mfr.magneticFieldX();
  double magnetic_field_y = mfr.magneticFieldY();
  double magnetic_field_z = mfr.magneticFieldZ();
  // get the acceleration of the car
  double acceleration_y = ar.accelerationY();
  double acceleration_x = ar.accelerationX();
  double acceleration_z = ar.accelerationZ();
  // get the angular velocity of the car
  double angular_velocity_x = vel.angularVelocityX();
  double angular_velocity_y = vel.angularVelocityY();
  double angular_velocity_z = vel.angularVelocityZ();

  cv::Point blue_center = blue_cone.getCenter();
  cv::Point yellow_center = yellow_cone.getCenter();
  double car_heading = gr.heading();
  //

  // display the blue distance and the yellow distance on the screen
  std::string blue_distance_str = std::to_string(blue_distance);
  std::string yellow_distance_str = std::to_string(yellow_distance);
  cv::putText(imgs.main, blue_distance_str, cv::Point(10, 30),
              cv::FONT_HERSHEY_SIMPLEX, 1, color_blue, 2);
  cv::putText(imgs.main, yellow_distance_str, cv::Point(10, 60),
              cv::FONT_HERSHEY_SIMPLEX, 1, color_yellow, 2);

  // display on the screen the gr.latitude(), gr.longitude(), gr.heading()
  std::ostringstream oss;
  // oss << " Heading: " << gr.heading();
  // cv::putText(imgs.fr_cropped, oss.str(), cv::Point(10, 20),
  // cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 255, 255), 1, CV_AA);

  // check if blue center is to the left of the car
  if (blue_detected && yellow_detected)
  {
    if (blue_center.x < car.x)
    {
      blue_is_left = true;
    }
    else
    {
      blue_is_left = false;
    }
  }
  std::cout << "yellow angle:  " << yellow_angle_from_car << std::endl;
  std::cout << "blue angle:  " << blue_angle_from_car << std::endl;

  // if (blue_detected && !yellow_detected)
  // {
  //    // get the middle point between the blue cone and the yellow cone
  //    cv::Point middle = cv::Point((blue_center.x + yellow_center.x) / 2,
  //    (blue_center.y + yellow_center.y) / 2);
  //    // get the angle of the middle point from the car in radians
  //    double middle_angle_from_car = middle.getAngleFrom(car);
  //   // correct the steering angle to have the car align with the middle point
  //    return middle_angle_from_car;
  // }
  // if (!blue_is_left && blue_detected && !yellow_detected &&
  //     blue_distance < 200) {
  //   return MAX_STEERING_VALUE;
  // } else if (!blue_is_left && yellow_detected && !blue_detected &&
  //            yellow_distance < 200) {
  //   return -MAX_STEERING_VALUE;
  // }
  // if (blue_detected && yellow_detected && blue_distance > 300 &&
  //     yellow_distance > 300)
  // {
  if (blue_distance > 320 && yellow_distance > 340)
  {
    return 0;
  }

  if (blue_detected && blue_is_left && (blue_distance < threshold))
  {
    double turn_intensity = (threshold - blue_distance) / 50;
    std::cout << "blue is left. b_distance: " << blue_distance << std::endl;
    if (blue_distance < 130)
    {
      return -MAX_STEERING_VALUE;
    }
    blue_correction = CLOCKWISE_RIGHT * turn_intensity * (blue_angle_from_car / 4) * (vel.angularVelocityZ()/-10);
    if (blue_correction < -MAX_STEERING_VALUE)
    {
      return -MAX_STEERING_VALUE;
    }
    else
    {
      std::cout << "steering: " << blue_correction << std::endl;
      return blue_correction;
    }
  }

  if (blue_detected && !blue_is_left && (blue_distance < threshold))
  {
    double turn_intensity = (threshold - blue_distance) / 50;
    // std::cout << "blue is right. b_distance: " << blue_distance << std::endl;
    // "turn_intensity: " << turn_intensity << "b_mag: " << blue_angle_from_car
    // << std::endl;
    if (blue_distance < 130)
    {
      return MAX_STEERING_VALUE;
    }
    blue_correction =
        COUNTERCLOCKWISE_LEFT * turn_intensity * (blue_angle_from_car / 4) * (vel.angularVelocityZ()/10);
    if (blue_correction > MAX_STEERING_VALUE)
    {
      return MAX_STEERING_VALUE;
    }
    else
      return blue_correction;
  }

  if (yellow_detected && blue_is_left && (yellow_distance < threshold))
  {
    double turn_intensity = (threshold - yellow_distance) / 50;
    std::cout << "yellow is right. y_distance: " << yellow_distance << std::endl;
    if (yellow_distance < 130)
    {
      return MAX_STEERING_VALUE;
    }
    yellow_correction = CLOCKWISE_LEFT * turn_intensity * (yellow_angle_from_car / 4) * (vel.angularVelocityZ()/10);
    if (yellow_correction > MAX_STEERING_VALUE)
    {
      return MAX_STEERING_VALUE;
    }
    else
      return yellow_correction;
  }

  if (yellow_detected && !blue_is_left && (yellow_distance < threshold))
  {
    double turn_intensity = (threshold - yellow_distance) / 50;
    std::cout << "yellow is left. y_distance: " << yellow_distance << std::endl;
    // "turn_intensity: " << turn_intensity << " y_mag: " <<
    // yellow_angle_from_car << std::endl;
    if (yellow_distance < 130)
    {
      return -MAX_STEERING_VALUE;
    }
    yellow_correction =
        COUNTERCLOCKWISE_RIGHT * turn_intensity * (yellow_angle_from_car / 4) * (vel.angularVelocityZ()/-10);
    if (yellow_correction < -MAX_STEERING_VALUE)
    {
      return -MAX_STEERING_VALUE;
    }
    else
      return yellow_correction;
  }
  return 0;
}


int32_t main(int32_t argc, char **argv)
{
  int32_t retCode{1};
  // Parse the command line parameters as we require the user to specify some
  // mandatory information on startup.
  auto commandlineArguments = cluon::getCommandlineArguments(argc, argv);
  if ((0 == commandlineArguments.count("cid")) ||
      (0 == commandlineArguments.count("name")) ||
      (0 == commandlineArguments.count("width")) ||
      (0 == commandlineArguments.count("height")) ||
      (0 == commandlineArguments.count("output")))
  {
    std::cerr << argv[0]
              << " attaches to a shared memory area containing an ARGB image."
              << std::endl;
    std::cerr << "Usage:   " << argv[0]
              << " --cid=<OD4 session> --name=<name of shared memory area> "
                 "[--verbose]"
                 "[--output]"
              << std::endl;
    std::cerr << "         --cid:    CID of the OD4Session to send and receive "
                 "messages"
              << std::endl;
    std::cerr << "         --name:   name of the shared memory area to attach"
              << std::endl;
    std::cerr << "         --width:  width of the frame" << std::endl;
    std::cerr << "         --height: height of the frame" << std::endl;
    std::cerr << "Example: " << argv[0]
              << " --cid=253 --name=img --width=640 --height=480 --output=example.csv --verbose"
              << std::endl;
  }
  else
  {
    // Extract the values from the command line parameters
    const std::string NAME{commandlineArguments["name"]};
    const uint32_t WIDTH{
        static_cast<uint32_t>(std::stoi(commandlineArguments["width"]))};
    const uint32_t HEIGHT{
        static_cast<uint32_t>(std::stoi(commandlineArguments["height"]))};
    const bool VERBOSE{commandlineArguments.count("verbose") != 0};
    const std::string OUTPUT{commandlineArguments["output"]};
    // Attach to the shared memory.
    std::unique_ptr<cluon::SharedMemory> sharedMemory{
        new cluon::SharedMemory{NAME}};

    if (sharedMemory && sharedMemory->valid())
    {
      std::clog << argv[0] << ": Attached to shared memory '"
                << sharedMemory->name() << " (" << sharedMemory->size()
                << " bytes)." << std::endl;

      // Interface to a running OpenDaVINCI session where network messages are
      // exchanged. The instance od4 allows you to send and receive messages.
      cluon::OD4Session od4{
          static_cast<uint16_t>(std::stoi(commandlineArguments["cid"]))};
      if (VERBOSE)
      {
        cv::namedWindow(hsv_window_name, cv::WINDOW_NORMAL);
        cv::createTrackbar("Hue - low", hsv_window_name, &hsv_bounds.h.low,
                           179);
        cv::createTrackbar("Hue - high", hsv_window_name, &hsv_bounds.h.high,
                           179);
        cv::createTrackbar("Sat - low", hsv_window_name, &hsv_bounds.s.low,
                           255);
        cv::createTrackbar("Sat - high", hsv_window_name, &hsv_bounds.s.high,
                           255);
        cv::createTrackbar("Val - low", hsv_window_name, &hsv_bounds.v.low,
                           255);
        cv::createTrackbar("Val - high", hsv_window_name, &hsv_bounds.v.high,
                           255);
      }
      // Get the steering angle request
      opendlv::proxy::GroundSteeringRequest gsr;
      std::mutex gsrMutex;
      auto onGroundSteeringRequest = [&gsr,
                                      &gsrMutex](cluon::data::Envelope &&env)
      {
        std::lock_guard<std::mutex> lck(gsrMutex);
        gsr = cluon::extractMessage<opendlv::proxy::GroundSteeringRequest>(
            std::move(env));
      };
      od4.dataTrigger(opendlv::proxy::GroundSteeringRequest::ID(),
                      onGroundSteeringRequest);

      // get magnetic field
      opendlv::proxy::MagneticFieldReading mfr;
      std::mutex mfrMutex;
      auto getMagnetFieldReading = [&mfr,
                                    &mfrMutex](cluon::data::Envelope &&env)
      {
        std::lock_guard<std::mutex> lck(mfrMutex);
        mfr = cluon::extractMessage<opendlv::proxy::MagneticFieldReading>(
            std::move(env));
      };
      od4.dataTrigger(opendlv::proxy::MagneticFieldReading::ID(),
                      getMagnetFieldReading);

      // get acceleration
      opendlv::proxy::AccelerationReading ar;
      std::mutex arMutex;
      auto getAccelerationReading = [&ar,
                                     &arMutex](cluon::data::Envelope &&env)
      {
        std::lock_guard<std::mutex> lck(arMutex);
        ar = cluon::extractMessage<opendlv::proxy::AccelerationReading>(
            std::move(env));
      };
      od4.dataTrigger(opendlv::proxy::AccelerationReading::ID(),
                      getAccelerationReading);

      // get velocity
      opendlv::proxy::AngularVelocityReading vel;
      std::mutex velMutex;
      auto getVelocityReading = [&vel, &velMutex](cluon::data::Envelope &&env)
      {
        std::lock_guard<std::mutex> lck(velMutex);
        vel = cluon::extractMessage<opendlv::proxy::AngularVelocityReading>(
            std::move(env));
      };
      od4.dataTrigger(opendlv::proxy::AngularVelocityReading::ID(),
                      getVelocityReading);

      // get distance reading
      opendlv::proxy::DistanceReading dr;
      std::mutex drMutex;
      auto getDistanceReading = [&dr, &drMutex](cluon::data::Envelope &&env)
      {
        std::lock_guard<std::mutex> lck(drMutex);
        dr = cluon::extractMessage<opendlv::proxy::DistanceReading>(
            std::move(env));
      };
      od4.dataTrigger(opendlv::proxy::DistanceReading::ID(),
                      getDistanceReading);

      // get image reading
      opendlv::proxy::ImageReading ireading;
      std::mutex ireadingMutex;
      auto getImageReading = [&ireading,
                              &ireadingMutex](cluon::data::Envelope &&env)
      {
        std::lock_guard<std::mutex> lck(ireadingMutex);
        ireading =
            cluon::extractMessage<opendlv::proxy::ImageReading>(std::move(env));
      };
      od4.dataTrigger(opendlv::proxy::ImageReading::ID(), getImageReading);

      // get geolocation reading
      opendlv::logic::sensation::Geolocation gr;
      std::mutex grMutex;
      auto getGeolocationReading = [&gr,
                                    &grMutex](cluon::data::Envelope &&env)
      {
        std::lock_guard<std::mutex> lck(grMutex);
        gr = cluon::extractMessage<opendlv::logic::sensation::Geolocation>(
            std::move(env));
      };
      od4.dataTrigger(opendlv::logic::sensation::Geolocation::ID(),
                      getGeolocationReading);
      output = OUTPUT;
      // region on image (bounding box)
      //          (x, y,          width,    height)
      cv::Rect region_of_interest(0, HEIGHT / 2, WIDTH - 1, (HEIGHT / 5));
      // OpenCV data structure to hold an image.
      car = cv::Point(WIDTH / 2, HEIGHT / 1.3);

      // Endless loop; end the program by pressing Ctrl-C.
      while (od4.isRunning() && sharedMemory->valid())
      {
        std::stringstream ss; // stringstream to hold text for the image.
        // std::string timestamp; // timestamp :D
        std::pair<bool, cluon::data::TimeStamp> ts;

        // Wait for a new frame.
        sharedMemory->wait();
        // uint64_t start_f = cv::getTickCount();

        sharedMemory->lock();
        {
          ts = sharedMemory->getTimeStamp();
          cv::Mat wrapped(HEIGHT, WIDTH, CV_8UC4, sharedMemory->data());
          imgs.main = wrapped.clone(); // text
          // timestamp = get_timestamp(sharedMemory->getTimeStamp(),
          // (cluon::time::now()).seconds());
        }
        sharedMemory->unlock();

        // Cropped image frame (only need a small slice the rest is noice)
        imgs.fr_cropped = imgs.main(region_of_interest);
        // Blur the input image data
        cv::GaussianBlur(imgs.fr_cropped, imgs.img_blur, cv::Size(5, 5), 0);
        // cv::blur(imgs.fr_cropped, imgs.img_blur, cv::Size(7, 7));
        // convert bgr to hsv
        cv::cvtColor(imgs.img_blur, imgs.img_hsv, cv::COLOR_BGR2HSV);
        // calculate steering adjustment based on the distance from the center
        // of the image and the yellow and blue bounding boxes
        steering_angle = getSteeringAngle(mfr, ar, vel, gr);
        // std::cout << "steering angle : " << gsr.groundSteering()
        //           << " compsteer: " << steering_angle << std::endl;

        // ss << "Blue Detected:   " << (blue_detected ? "true" : "false");
        // cv::putText(imgs.main, ss.str(), cv::Point(10, 377),
        // cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1); ss.str("");
        // ss.clear();

        // ss << "Yellow Detected:   " << (yellow_detected ? "true" : "false");
        // cv::putText(imgs.main, ss.str(), cv::Point(10, 393),
        // cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1); ss.str("");
        // ss.clear();

        ss << "ActualDistanceReading:   " << dr.distance();
        cv::putText(imgs.main, ss.str(), cv::Point(10, 409),
                    cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();

        ss << "ActualSteering:   " << gsr.groundSteering();
        cv::putText(imgs.main, ss.str(), cv::Point(10, 425),
                    cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();

        ss << "ComputedSteering: " << steering_angle;
        cv::putText(imgs.main, ss.str(), cv::Point(10, 441),
                    cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();

        // ss << "AccelerationX: " << ar.accelerationX() <<"AccelerationY: " <<
        // ar.accelerationY(); cv::putText(imgs.main, ss.str(), cv::Point(10,
        // 457), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        // ss.str("");
        // ss.clear();

        ss << "VelocityZ: " << vel.angularVelocityZ();
        cv::putText(imgs.main, ss.str(), cv::Point(10, 457),
                    cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();
        std::string timestamp = turn_in_timestamp(ts, steering_angle);
        std::cout << timestamp << std::endl;
        // float *gsr_steer_angle = &gsr.groundSteering();
        ss << timestamp << ";" << gsr.groundSteering();
        std::cout << ss.str() << std::endl;
        csv_lines.push_back(ss.str());

        if (VERBOSE)
        {
          imgs.hsv_debug = imgs.img_hsv.clone();
          cv::blur(imgs.hsv_debug, imgs.hsv_debug, cv::Size(7, 7));
          cv::cvtColor(imgs.hsv_debug, imgs.hsv_debug, cv::COLOR_BGR2HSV);
          cv::inRange(
              imgs.hsv_debug,
              cv::Scalar(hsv_bounds.h.low, hsv_bounds.s.low, hsv_bounds.v.low),
              cv::Scalar(hsv_bounds.h.high, hsv_bounds.s.high,
                         hsv_bounds.v.high),
              imgs.hsv_debug);
          hsv_bounds.h.low = cv::getTrackbarPos("Hue - low", hsv_window_name);
          hsv_bounds.h.high = cv::getTrackbarPos("Hue - high", hsv_window_name);
          hsv_bounds.s.low = cv::getTrackbarPos("Sat - low", hsv_window_name);
          hsv_bounds.s.high = cv::getTrackbarPos("Sat - high", hsv_window_name);
          hsv_bounds.v.low = cv::getTrackbarPos("Val - low", hsv_window_name);
          hsv_bounds.v.high = cv::getTrackbarPos("Val - high", hsv_window_name);
          cv::imshow("FilterView", imgs.hsv_debug);
          cv::imshow(sharedMemory->name().c_str(), imgs.main);
          cv::waitKey(1);
        }
      }
    }
    retCode = 0;
  }
  if (output != "") {
    toCSV(output);
  }
  return retCode;
}
