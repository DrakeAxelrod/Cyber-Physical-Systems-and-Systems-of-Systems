#include "steering-angle-generator.hpp"

const std::string hsv_window_name = "HSVView";
// Matrix to store points of cones in HSV filter.
std::vector<std::vector<cv::Point>> blue_points;
std::vector<std::vector<cv::Point>> yellow_points;

// upper and lower bounds of the yellow and blue cones (hsv)
Bound<cv::Scalar> yellow(cv::Scalar(17, 89, 128), cv::Scalar(35, 175, 216));
Bound<cv::Scalar> blue(cv::Scalar(70, 43, 34), cv::Scalar(120, 255, 255));

HSVBounds hsv_bounds = HSVBounds(17, 35, 89, 175, 128, 216);
// center point of feed
cv::Point center_pt;
// booleans to trach whether a given cone has been detected
bool blue_detected = false;
bool yellow_detected = false;
double blue_magnitude = 0;
double yellow_magnitude = 0;
double steering_angle = 0;
double acceptable_noise = 0;
double threshold = 365;
bool blue_is_left = false;
bool check_orientation = false;
double blue_threshold;
double yellow_threshold;
int tstamp = 0; // timestamp of the last frame


Images imgs = Images();

// color blue as a scalar value BGR (blue, green, red)
cv::Scalar color_blue(255, 0, 0);
// color yellow as a scalar value BGR (blue, green, red)
cv::Scalar color_yellow(0, 255, 255);

// Constants
const double CLOCKWISE_LEFT = 0.1771807038;
const double CLOCKWISE_RIGHT = -0.1356987459;
const double COUNTERCLOCKWISE_LEFT = 0.1203680391;
const double COUNTERCLOCKWISE_RIGHT = -0.1308372994;

const double MEDIAN_TURN_VALUE = 0.14102119705;
const double MAX_STEERING_ANGLE = 0.290888;

bool detectBlueCones(cv::Mat hsv_frame)
{
  cv::findContours(hsv_frame, blue_points, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE, cv::Point());
  return blue_points.size() > 0 ? true : false;
}

bool detectYellowCones(cv::Mat hsv_frame)
{
  cv::findContours(hsv_frame, yellow_points, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE, cv::Point());
  return yellow_points.size() > 0 ? true : false;
}

double getDistance(cv::Rect bounding_box) {
  return (sqrt(pow(center_pt.x - bounding_box.x, 2) + pow(center_pt.y - bounding_box.y, 2)));
}

double getBlueConeDistance(cv::Mat cropped_frame)
{
  cv::Rect bounding_box(cv::Point(0, 0), cv::Size(0, 0));
  // create a bounding box from the contour points of the cone and draw it
  // only if the size of the bounding box is larger than a certain threshold
  for (auto &contour : blue_points)
  {
    cv::Rect box = cv::boundingRect(contour);
    cv::Point center;
    if (box.area() > acceptable_noise)
    {
      // draw the bounding box
      cv::rectangle(cropped_frame, box, color_blue, 2);
      // draw the center of the bounding box
      cv::Point center(box.x + box.width / 2, box.y + box.height / 2);
      cv::circle(cropped_frame, center, 5, color_blue, -1);
      // check if circle is to the left or right of the center point
      if (!check_orientation) {
        blue_is_left = (center.x < center_pt.x) ? true : false;
        check_orientation = true;
      }
      // draw the center of the bounding bounding box
      if (bounding_box.width > 0)
      {
        // calculate the angle between the center of the bounding box and the center of the bounding bounding box
        cv::Point bounding_center(bounding_box.x + bounding_box.width / 2, bounding_box.y + bounding_box.height / 2);
        blue_magnitude = atan2(center_pt.y - bounding_center.y, center_pt.x - bounding_center.x);
        // yellow_magnitude converted to degrees
        //blue_magnitude = blue_magnitude * 180 / M_PI;
        cv::circle(cropped_frame, bounding_center, 5, color_blue, -1);
        // draw a line between the center of the bounding bounding box and the center of the current bounding box
        cv::line(cropped_frame, bounding_center, bounding_center, color_blue, 2);
      }
      bounding_box = box;
    }
  }
  // calculate the distance from the center of the feed to the center of the bounding box
  return getDistance(bounding_box);
}

double getYellowConeDistance(cv::Mat cropped_frame)
{
  cv::Rect bounding_box(cv::Point(0, 0), cv::Size(0, 0));
  // create a bounding box from the contour points of the cone and draw it
  // only if the size of the bounding box is larger than a certain threshold
  for (auto &contour : yellow_points)
  {
    // cv::Rect bounding_box = cv::boundingRect(contour);
    cv::Rect box = cv::boundingRect(contour);
    cv::Point center;
    if (box.area() > acceptable_noise)
    {
      // draw the bounding box
      cv::rectangle(cropped_frame, box, color_yellow, 2);
      // draw the center of the bounding box
      cv::Point center(box.x + box.width / 2, box.y + box.height / 2);
      cv::circle(cropped_frame, center, 5, color_yellow, -1);
      // draw the center of the bounding bounding box
      if (bounding_box.width > 0)
      {
        cv::Point bounding_center(bounding_box.x + bounding_box.width / 2, bounding_box.y + bounding_box.height / 2);
        yellow_magnitude = atan2(center_pt.y - bounding_center.y, center_pt.x - bounding_center.x);
        // yellow_magnitude converted to degrees
        //yellow_magnitude = yellow_magnitude * 180 / M_PI;
        // calculate the angle between the center of the bounding box and the center of the bounding bounding box
        cv::circle(cropped_frame, bounding_center, 5, color_yellow, -1);
        // draw a line between the center of the bounding bounding box and the center of the current bounding box
        cv::line(cropped_frame, bounding_center, center, color_yellow, 2);
      }
      bounding_box = box;
    }
  }
  // calculate the distance from the center of the feed to the center of the bounding box
  return getDistance(bounding_box);
}

// calculate the give steering adjustment based on the
// distance of the blue & yellow cones from the center of the feed
float getSteeringAngle()
{
  double blue_correction = 0;
  double yellow_correction = 0;
  // segment blue
  cv::inRange(imgs.img_hsv, blue.low, blue.high, imgs.fr_hsv);
  blue_detected = detectBlueCones(imgs.fr_hsv);
  double blue_distance = getBlueConeDistance(imgs.fr_cropped);
  // segment yellow
  cv::inRange(imgs.img_hsv, yellow.low, yellow.high, imgs.fr_hsv);
  yellow_detected = detectYellowCones(imgs.fr_hsv);
  double yellow_distance = getYellowConeDistance(imgs.fr_cropped);
  if (blue_detected && yellow_detected) {
    return 0;
  }

  // yellow_magnitude = (yellow_magnitude / 100);
  // blue_magnitude = (blue_magnitude / 100);
  if (blue_is_left && (blue_distance < threshold)) {
    std::cout << "blue is left" << std::endl;
    if (blue_distance < 100) {
      return -MAX_STEERING_ANGLE;
    }
    blue_correction = -MEDIAN_TURN_VALUE * blue_magnitude;
    return blue_correction;
  }

  if (!blue_is_left && (blue_distance < threshold)) {
    std::cout << "blue is right" << std::endl;
    if (blue_distance < 100) {
      return MAX_STEERING_ANGLE;
    }
    blue_correction = MEDIAN_TURN_VALUE * blue_magnitude;
    return blue_correction;
  }

  if (blue_is_left && (yellow_distance < threshold)) {
    std::cout << "yellow is right" << std::endl;
    if (yellow_distance < 100) {
      return MAX_STEERING_ANGLE;
    }
    yellow_correction = MEDIAN_TURN_VALUE * yellow_magnitude;
    return yellow_correction;
  }

  if (!blue_is_left && (yellow_distance < threshold)) {
    std::cout << "yellow is left" << std::endl;
    if (yellow_distance < 100) {
      return -MAX_STEERING_ANGLE;
    }
    yellow_correction = -MEDIAN_TURN_VALUE * yellow_magnitude;
    return yellow_correction;
  }


  // if (blue_distance < threshold && yellow_distance < threshold)
  // {
  //   return 0;
  // }

  // if (blue_detected && blue_distance < threshold)
  // {
  //   double difference = threshold - blue_threshold;
  //   if (blue_is_left)
  //   {
  //     blue_correction = CLOCKWISE_RIGHT * blue_magnitude * (difference/400);
  //     //* blue_magnitude;
  //   }
  //   else
  //   {
      
  //     blue_correction = COUNTERCLOCKWISE_LEFT * blue_magnitude * (difference/400);
  //     //* blue_magnitude;
  //   }
  //   return blue_correction;
  // }
  // if (yellow_detected && yellow_distance < threshold)
  // {
  //   double difference = (threshold - yellow_distance)/50;
  //   if (blue_is_left)
  //   {
  //     yellow_correction = CLOCKWISE_LEFT * yellow_magnitude;
  //     //* yellow_magnitude;
  //   }
  //   else
  //   {
  //     yellow_correction = COUNTERCLOCKWISE_RIGHT * yellow_magnitude;
  //     //yellow_magnitude;
  //   }
  //   return yellow_correction;
  // }
  // return 0;
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
      (0 == commandlineArguments.count("height")))
  {
    std::cerr << argv[0]
              << " attaches to a shared memory area containing an ARGB image."
              << std::endl;
    std::cerr << "Usage:   " << argv[0]
              << " --cid=<OD4 session> --name=<name of shared memory area> "
                 "[--verbose]"
              << std::endl;
    std::cerr << "         --cid:    CID of the OD4Session to send and receive "
                 "messages"
              << std::endl;
    std::cerr << "         --name:   name of the shared memory area to attach"
              << std::endl;
    std::cerr << "         --width:  width of the frame"
              << std::endl;
    std::cerr << "         --height: height of the frame"
              << std::endl;
    std::cerr << "Example: " << argv[0]
              << " --cid=253 --name=img --width=640 --height=480 --verbose"
              << std::endl;
  }
  else
  {
    // Extract the values from the command line parameters
    const std::string NAME{commandlineArguments["name"]};
    const uint32_t WIDTH{static_cast<uint32_t>(std::stoi(commandlineArguments["width"]))};
    const uint32_t HEIGHT{static_cast<uint32_t>(std::stoi(commandlineArguments["height"]))};
    const bool VERBOSE{commandlineArguments.count("verbose") != 0};

    // Attach to the shared memory.
    std::unique_ptr<cluon::SharedMemory> sharedMemory{new cluon::SharedMemory{NAME}};
    if (sharedMemory && sharedMemory->valid())
    {
      std::clog << argv[0] << ": Attached to shared memory '" << sharedMemory->name()
                << " (" << sharedMemory->size()
                << " bytes)." << std::endl;

      // Interface to a running OpenDaVINCI session where network messages are
      // exchanged. The instance od4 allows you to send and receive messages.
      cluon::OD4Session od4{static_cast<uint16_t>(std::stoi(commandlineArguments["cid"]))};
      if (VERBOSE)
      {
        cv::namedWindow(hsv_window_name, cv::WINDOW_NORMAL);
        cv::createTrackbar("Hue - low", hsv_window_name, &hsv_bounds.h.low, 179);
        cv::createTrackbar("Hue - high", hsv_window_name, &hsv_bounds.h.high, 179);
        cv::createTrackbar("Sat - low", hsv_window_name, &hsv_bounds.s.low, 255);
        cv::createTrackbar("Sat - high", hsv_window_name, &hsv_bounds.s.high, 255);
        cv::createTrackbar("Val - low", hsv_window_name, &hsv_bounds.v.low, 255);
        cv::createTrackbar("Val - high", hsv_window_name, &hsv_bounds.v.high, 255);
      }
      // Get the steering angle request
      opendlv::proxy::GroundSteeringRequest gsr;
      std::mutex gsrMutex;
      auto onGroundSteeringRequest = [&gsr, &gsrMutex](cluon::data::Envelope &&env)
      {
        std::lock_guard<std::mutex> lck(gsrMutex);
        gsr = cluon::extractMessage<opendlv::proxy::GroundSteeringRequest>(std::move(env));
      };
      od4.dataTrigger(opendlv::proxy::GroundSteeringRequest::ID(), onGroundSteeringRequest);

      // get magnetic field
      opendlv::proxy::MagneticFieldReading mfr;
      std::mutex mfrMutex;
      auto getMagnetFieldReading = [&mfr, &mfrMutex](cluon::data::Envelope &&env)
      {
        std::lock_guard<std::mutex> lck(mfrMutex);
        mfr = cluon::extractMessage<opendlv::proxy::MagneticFieldReading>(std::move(env));
      };
      od4.dataTrigger(opendlv::proxy::MagneticFieldReading::ID(), getMagnetFieldReading);

      // get distance reading
      opendlv::proxy::DistanceReading dr;
      std::mutex drMutex;
      auto getDistanceReading = [&dr, &drMutex](cluon::data::Envelope &&env)
      {
        std::lock_guard<std::mutex> lck(drMutex);
        dr = cluon::extractMessage<opendlv::proxy::DistanceReading>(std::move(env));
      };
      od4.dataTrigger(opendlv::proxy::DistanceReading::ID(), getDistanceReading);

      // get image reading
      opendlv::proxy::ImageReading ireading;
      std::mutex ireadingMutex;
      auto getImageReading = [&ireading, &ireadingMutex](cluon::data::Envelope &&env)
      {
        std::lock_guard<std::mutex> lck(ireadingMutex);
        ireading = cluon::extractMessage<opendlv::proxy::ImageReading>(std::move(env));
      };
      od4.dataTrigger(opendlv::proxy::ImageReading::ID(), getImageReading);
      // region on image (bounding box)
      //          (x, y,          width,    height)
      cv::Rect region_of_interest(0, HEIGHT / 2, WIDTH - 1, (HEIGHT / 5));
      // OpenCV data structure to hold an image.
      center_pt = cv::Point(WIDTH / 2, HEIGHT / 1.3);

      // Endless loop; end the program by pressing Ctrl-C.
      while (od4.isRunning())
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
          // timestamp = get_timestamp(sharedMemory->getTimeStamp(), (cluon::time::now()).seconds());
        }
        sharedMemory->unlock();

        // Cropped image frame (only need a small slice the rest is noice)
        imgs.fr_cropped = imgs.main(region_of_interest);
        // Blur the input image data
        cv::GaussianBlur(imgs.fr_cropped, imgs.img_blur, cv::Size(5, 5), 0);
        // cv::blur(imgs.fr_cropped, imgs.img_blur, cv::Size(7, 7));
        // convert bgr to hsv
        cv::cvtColor(imgs.img_blur, imgs.img_hsv, cv::COLOR_BGR2HSV);
        // calculate steering adjustment based on the distance from the center of the image
        // and the yellow and blue bounding boxes
        steering_angle = getSteeringAngle();

        ss << "Blue Detected:   " << (blue_detected ? "true" : "false");
        cv::putText(imgs.main, ss.str(), cv::Point(10, 377), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();

        ss << "Yellow Detected:   " << (yellow_detected ? "true" : "false");
        cv::putText(imgs.main, ss.str(), cv::Point(10, 393), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();

        ss << "ActualDistanceReading:   " << dr.distance();
        cv::putText(imgs.main, ss.str(), cv::Point(10, 409), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();

        ss << "ActualSteering:   " << gsr.groundSteering();
        cv::putText(imgs.main, ss.str(), cv::Point(10, 425), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();

        ss << "ComputedSteering: " << steering_angle;
        cv::putText(imgs.main, ss.str(), cv::Point(10, 441), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();

        // get the ending frame tick count -> performance calculation
        // uint64_t end_f = cv::getTickCount();
        // the turn in time stamp requirement
        // turn_in_timestamp(ts, steering_angle);
        // turn_in_timestamp(ts, gsr.groundSteering());
        if (ts.second.seconds() == 1584542901)
        {
          std::string str = "FINISHED";
          sendData(str);
        }
        ss << gsr.groundSteering() << "|" << steering_angle;
        sendData(ss.str());
        ss.str("");
        ss.clear();
        std::cout << "actual steering:    " << gsr.groundSteering() << std::endl;
        std::cout << "computed steering:  "
                  << steering_angle
                  << ", bmag: "
                  << blue_magnitude
                  << ", ymag: "
                  << yellow_magnitude
                  << std::endl;
        if (VERBOSE)
        {
          imgs.hsv_debug = imgs.img_hsv.clone();
          cv::blur(imgs.hsv_debug, imgs.hsv_debug, cv::Size(7, 7));
          cv::cvtColor(imgs.hsv_debug, imgs.hsv_debug, cv::COLOR_BGR2HSV);
          cv::inRange(imgs.hsv_debug,
                      cv::Scalar(hsv_bounds.h.low, hsv_bounds.s.low, hsv_bounds.v.low),
                      cv::Scalar(hsv_bounds.h.high, hsv_bounds.s.high, hsv_bounds.v.high),
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
  return retCode;
}
