#include "steering-angle-generator.hpp"

const std::string hsv_window_name = "HSVView";
// Matrix to store points of cones in HSV filter.
std::vector<std::vector<cv::Point>> b_pts;
std::vector<std::vector<cv::Point>> y_pts;

// upper and lower bounds of the yellow and blue cones (hsv)
Bound<cv::Scalar> yellow(cv::Scalar(17, 89, 128), cv::Scalar(35, 175, 216));
Bound<cv::Scalar> blue(cv::Scalar(70, 43, 34), cv::Scalar(120, 255, 255));

HSVBounds hsv_bounds = HSVBounds(17, 35, 89, 175, 128, 216);
// center point of feed
cv::Point center_pt;
// booleans to trach whether a given cone has been detected
bool b_detected = false;
bool y_detected = false;
float steering_angle = 0;
float threshold = 50;
//
struct Images
{
  cv::Mat main;
  cv::Mat fr_hsv;
  cv::Mat fr_cropped;
  cv::Mat img_hsv;
  cv::Mat img_blur;
  cv::Mat img_cropped;
  cv::Mat hsv_debug;
} Imgs;

bool detectBlueCones(cv::Mat hsv_frame)
{
  cv::findContours(hsv_frame, b_pts, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE, cv::Point());
  return b_pts.size() > 0 ? true : false;
}

bool detectYellowCones(cv::Mat hsv_frame)
{
  cv::findContours(hsv_frame, y_pts, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE, cv::Point());
  return y_pts.size() > 0 ? true : false;
}

cv::Rect getBlueBoundingBox(cv::Mat cropped_frame, float distance)
{
  // bgr (blue, green, red)
  cv::Scalar blue(255, 0, 0);
  cv::Rect previous_box(cv::Point(0, 0), cv::Size(0, 0));
  // create a bounding box from the contour points of the cone and draw it
  // only if the size of the bounding box is larger than a certain threshold
  for (auto &contour : b_pts)
  {
    cv::Rect bounding_box = cv::boundingRect(contour);
    if (bounding_box.area() > threshold)
    {
      cv::Rect box = cv::boundingRect(contour);
      // draw the bounding box
      cv::rectangle(cropped_frame, box, blue, 2);
      // draw the center of the bounding box
      cv::Point center(box.x + box.width / 2, box.y + box.height / 2);
      cv::circle(cropped_frame, center, 5, blue, -1);
      // draw the center of the previous bounding box
      if (previous_box.width > 0)
      {
        cv::Point previous_center(previous_box.x + previous_box.width / 2, previous_box.y + previous_box.height / 2);
        cv::circle(cropped_frame, previous_center, 5, blue, -1);
        // draw a line between the center of the previous bounding box and the center of the current bounding box
        cv::line(cropped_frame, previous_center, center, blue, 2);
      }
      previous_box = box;
    }
  }
  // turn box red if the bounding box is withing a certain distance of the center of the feed
  if (previous_box.width > 0)
  {
    if (center_pt.x - previous_box.x < distance)
    {
      // turn the box red if the bounding box is inside the distance threshold
      cv::rectangle(cropped_frame, previous_box, cv::Scalar(0, 0, 255), 2);
    }
    else
    {
      // turn the box green if the bounding box is outside the distance threshold
      cv::rectangle(cropped_frame, previous_box, cv::Scalar(0, 255, 0), 2);
    }
  }
  return previous_box;
}

cv::Rect getYellowBoundingBox(cv::Mat cropped_frame, float distance)
{
  // bgr (blue, green, red)
  cv::Scalar yellow(0, 255, 255);
  cv::Rect previous_box(cv::Point(0, 0), cv::Size(0, 0));
  // create a bounding box from the contour points of the cone and draw it
  // only if the size of the bounding box is larger than a certain threshold
  for (auto &contour : y_pts)
  {
    cv::Rect bounding_box = cv::boundingRect(contour);
    if (bounding_box.area() > threshold)
    {
      cv::Rect box = cv::boundingRect(contour);
      // draw the bounding box
      cv::rectangle(cropped_frame, box, yellow, 2);
      // draw the center of the bounding box
      cv::Point center(box.x + box.width / 2, box.y + box.height / 2);
      cv::circle(cropped_frame, center, 5, yellow, -1);
      // draw the center of the previous bounding box
      if (previous_box.width > 0)
      {
        cv::Point previous_center(previous_box.x + previous_box.width / 2, previous_box.y + previous_box.height / 2);
        cv::circle(cropped_frame, previous_center, 5, yellow, -1);
        // draw a line between the center of the previous bounding box and the center of the current bounding box
        cv::line(cropped_frame, previous_center, center, yellow, 2);
      }
      previous_box = box;
    }
  }

  // turn box red if the bounding box is withing a certain distance of the center of the feed
  if (previous_box.width > 0)
  {
    if (center_pt.x - previous_box.x < distance)
    {
      // turn the box red if the bounding box is inside the distance threshold
      cv::rectangle(cropped_frame, previous_box, cv::Scalar(0, 0, 255), 2);
    }
    else
    {
      // turn the box green if the bounding box is outside the distance threshold
      cv::rectangle(cropped_frame, previous_box, cv::Scalar(0, 255, 0), 2);
    }
  }
  return previous_box;
}

float getAngle(cv::Rect box, cv::Point center)
{
  // get the angle between the center of the bounding box and the center of the feed
  float angle = atan2(center_pt.y - center.y, center_pt.x - center.x) * 180 / 3.14;
  // turn the angle positive if it is negative
  if (angle < 0)
  {
    angle = angle + 360;
  }
  // get the angle between the center of the bounding box and the center of the feed
  float angle_2 = atan2(center_pt.y - box.y, center_pt.x - box.x) * 180 / 3.14;
  // turn the angle positive if it is negative
  if (angle_2 < 0)
  {
    angle_2 = angle_2 + 360;
  }
  // return the difference between the two angles
  return angle_2 - angle;
}

void getSteeringAngle(cv::Rect box, cv::Point center)
{
  // get the angle between the center of the bounding box and the center of the feed
  float angle = atan2(center_pt.y - center.y, center_pt.x - center.x) * 180 / 3.14;
  // turn the angle positive if it is negative
  if (angle < 0)
  {
    angle = angle + 360;
  }
  // get the angle between the center of the bounding box and the center of the feed
  float angle_2 = atan2(center_pt.y - box.y, center_pt.x - box.x) * 180 / 3.14;
  // turn the angle positive if it is negative
  if (angle_2 < 0)
  {
    angle_2 = angle_2 + 360;
  }
  // return the difference between the two angles
  steering_angle = angle_2 - angle;
}



// calculate the give steering adjustment based on the
// distance of the blue cones bounding box from the center of the feed
// distance of the yellow cones bounding box from the center of the feed
float getSteeringAngle(float distance)
{
  // segment blue
  cv::inRange(Imgs.img_hsv, blue.low, blue.high, Imgs.fr_hsv);
  b_detected = detectBlueCones(Imgs.fr_hsv);
  cv::Rect b_bounding_box(getBlueBoundingBox(Imgs.fr_cropped, distance));
  // segment yellow
  cv::inRange(Imgs.img_hsv, yellow.low, yellow.high, Imgs.fr_hsv);
  y_detected = detectYellowCones(Imgs.fr_hsv);
  cv::Rect y_bounding_box(getYellowBoundingBox(Imgs.fr_cropped, distance));
  // get the current steering angle based on the bounding boxes

  // draw the center point as a green colored circle when distance is greater than the threshold
  // and a red colored circle when distance is less than the threshold
  if (distance > threshold)
  {
    cv::circle(Imgs.fr_cropped, center_pt, 5, cv::Scalar(0, 255, 0), -1);
  }
  else
  {
    cv::circle(Imgs.fr_cropped, center_pt, 5, cv::Scalar(0, 0, 255), -1);
  }
  // determine whether the yellow cone or the blue cone is closer
  if (y_bounding_box.width > b_bounding_box.width)
  {
    return getAngle(y_bounding_box, center_pt);
  }
  else
  {
    return getAngle(b_bounding_box, center_pt);
  }
  // TODO currently not complete so return 0.0
  return 0.0;
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
    std::cerr << "         --width:  width of the frame" << std::endl;
    std::cerr << "         --height: height of the frame" << std::endl;
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
      //          (x,          y,     width,        height)
      cv::Rect roi(0, HEIGHT / 2, WIDTH - 1, (HEIGHT / 5));
      // OpenCV data structure to hold an image.
      center_pt = cv::Point(WIDTH / 2, roi.height);

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
          Imgs.main = wrapped.clone(); // text
          // timestamp = get_timestamp(sharedMemory->getTimeStamp(), (cluon::time::now()).seconds());
        }
        sharedMemory->unlock();

        // Cropped image frame (only need a small slice the rest is noice)
        Imgs.fr_cropped = Imgs.main(roi);
        // Blur the input image data
        cv::GaussianBlur(Imgs.fr_cropped, Imgs.img_blur, cv::Size(5, 5), 0);
        // cv::blur(Imgs.fr_cropped, Imgs.img_blur, cv::Size(7, 7));
        // convert bgr to hsv
        cv::cvtColor(Imgs.img_blur, Imgs.img_hsv, cv::COLOR_BGR2HSV);
        // calculate steering adjustment based on the distance from the center of the image
        // and the yellow and blue bounding boxes
        steering_angle = getSteeringAngle(dr.distance());

        ss << "Blue Detected:   " << (b_detected ? "true" : "false");
        cv::putText(Imgs.main, ss.str(), cv::Point(10, 377), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();

        ss << "Yellow Detected:   " << (y_detected ? "true" : "false");
        cv::putText(Imgs.main, ss.str(), cv::Point(10, 393), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();

        ss << "ActualDistanceReading:   " << dr.distance();
        cv::putText(Imgs.main, ss.str(), cv::Point(10, 409), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();

        ss << "ActualSteering:   " << gsr.groundSteering();
        cv::putText(Imgs.main, ss.str(), cv::Point(10, 425), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();

        ss << "ComputedSteering: " << steering_angle;
        cv::putText(Imgs.main, ss.str(), cv::Point(10, 441), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();

        // get the ending frame tick count -> performance calculation
        // uint64_t end_f = cv::getTickCount();
        // the turn in time stamp requirement
        turn_in_timestamp(ts, steering_angle);
        if (VERBOSE)
        {
          Imgs.hsv_debug = Imgs.img_hsv.clone();
          cv::blur(Imgs.hsv_debug, Imgs.hsv_debug, cv::Size(7, 7));
          cv::cvtColor(Imgs.hsv_debug, Imgs.hsv_debug, cv::COLOR_BGR2HSV);
          cv::inRange(Imgs.hsv_debug,
                      cv::Scalar(hsv_bounds.h.low, hsv_bounds.s.low, hsv_bounds.v.low),
                      cv::Scalar(hsv_bounds.h.high, hsv_bounds.s.high, hsv_bounds.v.high),
                      Imgs.hsv_debug);
          hsv_bounds.h.low = cv::getTrackbarPos("Hue - low", hsv_window_name);
          hsv_bounds.h.high = cv::getTrackbarPos("Hue - high", hsv_window_name);
          hsv_bounds.s.low = cv::getTrackbarPos("Sat - low", hsv_window_name);
          hsv_bounds.s.high = cv::getTrackbarPos("Sat - high", hsv_window_name);
          hsv_bounds.v.low = cv::getTrackbarPos("Val - low", hsv_window_name);
          hsv_bounds.v.high = cv::getTrackbarPos("Val - high", hsv_window_name);
          cv::imshow("FilterView", Imgs.hsv_debug);
          cv::imshow(sharedMemory->name().c_str(), Imgs.main);
          cv::waitKey(1);
        }
      }
    }
    retCode = 0;
  }
  return retCode;
}
