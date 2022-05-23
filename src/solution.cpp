// This is a vernita comment which is super important!
#include "steering-angle-generator.hpp"
#include <limits>
#include <fstream>
const std::string hsv_window_name = "HSVView";
std::vector<std::vector<cv::Point>> blue_points;
std::vector<std::vector<cv::Point>> yellow_points;

Bound<cv::Scalar> yellow(cv::Scalar(17, 89, 128), cv::Scalar(35, 175, 216));
Bound<cv::Scalar> blue(cv::Scalar(70, 43, 34), cv::Scalar(120, 255, 255));

HSVBounds hsv_bounds = HSVBounds(17, 35, 89, 175, 128, 216);
cv::Point car;
double steering_angle = 0;
double threshold = 333;
bool blue_is_left;
Images imgs = Images();
cv::Scalar color_blue(255, 0, 0);
cv::Scalar color_yellow(0, 255, 255);
const double CLOCKWISE_LEFT = 0.1171807038;
const double CLOCKWISE_RIGHT = -0.1356987459;
const double COUNTERCLOCKWISE_LEFT = 0.1203680391;
const double COUNTERCLOCKWISE_RIGHT = -0.1308372994;
const double MEDIAN_TURN_VALUE = 0.14102119705;
const double MAX_STEERING_VALUE = 0.290888;
const int NOISE_THRESHOLD = 0;

std::vector<std::string> csv_lines = std::vector<std::string>();
std::string output;
void toCSV(std::string filepath)
{
  std::ofstream myfile;
  myfile.open(filepath);
  for (int i = 0; i < csv_lines.size(); i++)
  {
    myfile << csv_lines[i] << std::endl;
  }
  myfile.close();
}

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
  cv::Rect getBox() { return box; }
  cv::Scalar getColor() { return color; }
  double getAngleFrom(cv::Point point)
  {
    double angle = atan2(point.y - box.y - box.height / 2,
                         point.x - box.x - box.width / 2);
    return angle;
  }
  double getDistanceFrom(cv::Point point)
  {
    return sqrt(pow(point.x - box.x - box.width / 2, 2) +
                pow(point.y - box.y - box.height / 2, 2));
  }
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
  cv::Rect box(cv::Point(0, 0), cv::Size(0, 0));
  cv::rectangle(cropped_frame, box, color, 2);
  for (auto &contour : matrix)
  {
    cv::Rect tmp = cv::boundingRect(contour);
    if (tmp.area() > NOISE_THRESHOLD)
    {
      cv::Rect tmp = cv::boundingRect(contour);
      cv::Point tmp_center =
          cv::Point(tmp.x + tmp.width / 2, tmp.y + tmp.height / 2);
      cv::rectangle(cropped_frame, tmp, color, 2);
      cv::circle(cropped_frame, tmp_center, 5, color, -1);
      if (box.width > 0)
      {
        cv::Point center =
            cv::Point(box.x + box.width / 2, box.y + box.height / 2);
        cv::rectangle(cropped_frame, box, color, 2);
        cv::circle(cropped_frame, center, 5, color, -1);
        cv::line(cropped_frame, center, tmp_center, color, 2);
      }
      box = tmp;
    }
  }
  return Cone(box, color);
}

double getSteeringAngle(opendlv::proxy::MagneticFieldReading mfr,
                        opendlv::proxy::AccelerationReading ar,
                        opendlv::proxy::AngularVelocityReading vel,
                        opendlv::logic::sensation::Geolocation gr)
{
  double blue_correction = 0;
  double yellow_correction = 0;
  cv::inRange(imgs.img_hsv, blue.low, blue.high, imgs.fr_hsv);
  bool blue_detected = detectBlueCones(imgs.fr_hsv);
  Cone blue_cone =
      getCone(imgs.fr_cropped, imgs.fr_hsv, color_blue, blue_points);
  cv::inRange(imgs.img_hsv, yellow.low, yellow.high, imgs.fr_hsv);
  bool yellow_detected = detectYellowCones(imgs.fr_hsv);
  Cone yellow_cone =
      getCone(imgs.fr_cropped, imgs.fr_hsv, color_yellow, yellow_points);
  double yellow_angle_from_car = yellow_cone.getAngleFrom(car);
  double blue_angle_from_car = blue_cone.getAngleFrom(car);
  double blue_distance = blue_cone.getDistanceFrom(car);
  double yellow_distance = yellow_cone.getDistanceFrom(car);

  cv::Point yellow_center = yellow_cone.getCenter();
  cv::Point blue_center = blue_cone.getCenter();
  double car_heading = gr.heading();

  std::string blue_distance_str = std::to_string(blue_distance);
  std::string yellow_distance_str = std::to_string(yellow_distance);
  cv::putText(imgs.main, blue_distance_str, cv::Point(10, 30),
              cv::FONT_HERSHEY_SIMPLEX, 1, color_blue, 2);
  cv::putText(imgs.main, yellow_distance_str, cv::Point(10, 60),
              cv::FONT_HERSHEY_SIMPLEX, 1, color_yellow, 2);

  std::ostringstream oss;

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

  if (!blue_is_left && blue_detected && !yellow_detected &&
      blue_distance < 220 && yellow_distance > 488)
  {
    return MAX_STEERING_VALUE;
  }
  else if (blue_is_left && blue_detected && !yellow_detected &&
           blue_distance < 220 && yellow_distance > 488)
  {
    return -MAX_STEERING_VALUE;
  }
  if (blue_detected && yellow_detected && blue_distance > 300 &&
      yellow_distance > 300)
  {
    return 0;
  }

  double angular_velocity_z = vel.angularVelocityZ(); 

  if (blue_detected && blue_is_left && (blue_distance < threshold))
  {
    double turn_intensity = (threshold - blue_distance) / 50;
    if (blue_distance < 120)
    {
      return -MAX_STEERING_VALUE;
    }
    blue_correction = CLOCKWISE_RIGHT * turn_intensity * (blue_angle_from_car / 4) * (angular_velocity_z / -10);
    if (blue_correction < -MAX_STEERING_VALUE)
    {
      return -MAX_STEERING_VALUE;
    }
    else
    {
      return blue_correction;
    }
  }

  if (blue_detected && !blue_is_left && (blue_distance < threshold))
  {
    double turn_intensity = (threshold - blue_distance) / 50;
    if (blue_distance < 120)
    {
      return MAX_STEERING_VALUE;
    }
    blue_correction =
        COUNTERCLOCKWISE_LEFT * turn_intensity * (blue_angle_from_car / 4) * (angular_velocity_z / 10);
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
    if (yellow_distance < 120)
    {
      return MAX_STEERING_VALUE;
    }
    yellow_correction = CLOCKWISE_LEFT * turn_intensity * (yellow_angle_from_car / 4) * (angular_velocity_z / 10);
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
    if (yellow_distance < 120)
    {
      return -MAX_STEERING_VALUE;
    }
    yellow_correction =
        COUNTERCLOCKWISE_RIGHT * turn_intensity * (yellow_angle_from_car / 4) * (angular_velocity_z / -10);
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
    const std::string NAME{commandlineArguments["name"]};
    const uint32_t WIDTH{
        static_cast<uint32_t>(std::stoi(commandlineArguments["width"]))};
    const uint32_t HEIGHT{
        static_cast<uint32_t>(std::stoi(commandlineArguments["height"]))};
    const bool VERBOSE{commandlineArguments.count("verbose") != 0};
    const std::string OUTPUT{commandlineArguments["output"]};
    std::unique_ptr<cluon::SharedMemory> sharedMemory{
        new cluon::SharedMemory{NAME}};

    if (sharedMemory && sharedMemory->valid())
    {
      std::clog << argv[0] << ": Attached to shared memory '"
                << sharedMemory->name() << " (" << sharedMemory->size()
                << " bytes)." << std::endl;

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
      cv::Rect region_of_interest(0, HEIGHT / 2, WIDTH - 1, (HEIGHT / 5));
      car = cv::Point(WIDTH / 2, HEIGHT / 1.3);

      while (od4.isRunning() && sharedMemory->valid())
      {
        std::stringstream ss;
        std::pair<bool, cluon::data::TimeStamp> ts;
        std::string timestamp;
        sharedMemory->wait();

        sharedMemory->lock();
        {
          ts = sharedMemory->getTimeStamp();
          timestamp = std::to_string(cluon::time::toMicroseconds(ts.second));
          cv::Mat wrapped(HEIGHT, WIDTH, CV_8UC4, sharedMemory->data());
          imgs.main = wrapped.clone(); // text
        }
        sharedMemory->unlock();

        imgs.fr_cropped = imgs.main(region_of_interest);
        cv::GaussianBlur(imgs.fr_cropped, imgs.img_blur, cv::Size(5, 5), 0);
        cv::cvtColor(imgs.img_blur, imgs.img_hsv, cv::COLOR_BGR2HSV);
        steering_angle = getSteeringAngle(mfr, ar, vel, gr);

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

        cv::putText(imgs.main, ss.str(), cv::Point(10, 457),
                    cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();

        std::cout << "group_05;" << timestamp << ";" << steering_angle << std::endl;
        ss << "group_05;" << timestamp << ";" << steering_angle << ";" << gsr.groundSteering();
  
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
  if (output != "")
  {
    toCSV(output);
  }
  return retCode;
}
