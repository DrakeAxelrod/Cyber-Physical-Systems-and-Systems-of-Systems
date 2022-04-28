/*
 * Copyright (C) 2020  Christian Berger
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "steering-angle-generator.hpp"

const std::string hsv_window_name = "HSVView";
// Matrix to store points of cones in HSV filter.
std::vector<std::vector<cv::Point>> b_pts;
std::vector<std::vector<cv::Point>> y_pts;

Bound <cv::Scalar> yellow(cv::Scalar(17, 89, 128), cv::Scalar(35, 175, 216));
Bound <cv::Scalar> blue(cv::Scalar(70, 43, 34), cv::Scalar(120, 255, 255));

HSVBounds hsv_bounds = HSVBounds(17, 35, 89, 175, 128, 216);



cv::Point center_pt;

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
      std::clog << argv[0]    << ": Attached to shared memory '" << sharedMemory->name()
                << " ("       << sharedMemory->size()
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

      //          (x,          y,     width,        height)
      cv::Rect roi(0, HEIGHT / 2, WIDTH - 1,  (HEIGHT / 5));
      // OpenCV data structure to hold an image.
      // cv::Mat img, frame, img_blur, img_hsv, frame_hsv, frame_cropped, hsv_debug;
      struct {
        cv::Mat main;
        cv::Mat frame;
        cv::Mat fr_hsv;
        cv::Mat fr_cropped;
        cv::Mat img_hsv;
        cv::Mat img_blur;
        cv::Mat img_cropped;
        cv::Mat hsv_debug;
      } Imgs;
      center_pt = cv::Point(WIDTH / 2, roi.height);

      // Endless loop; end the program by pressing Ctrl-C.
      while (od4.isRunning())
      {
        std::stringstream ss; // stringstream to hold text for the image.
        std::string timestamp; // timestamp :D

        uint64_t start_f = cv::getTickCount();
  
        sharedMemory->lock();
        {
          cv::Mat wrapped(HEIGHT, WIDTH, CV_8UC4, sharedMemory->data());
          cv::Mat cropped(HEIGHT, WIDTH, CV_8UC1, sharedMemory->data());
          Imgs.frame = cropped.clone(); // frame
          Imgs.main = wrapped.clone(); // text
          timestamp = get_timestamp(sharedMemory->getTimeStamp(), (cluon::time::now()).seconds());
        }
        sharedMemory->unlock();

        cv::putText(Imgs.main, timestamp, cv::Point(10, 15), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();

        ss << "GroundSteering: " << gsr.groundSteering();
        cv::putText(Imgs.main, ss.str(), cv::Point(10, 31), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();

        ss << "MagneticField (x,y,z): "
           << "("
           << mfr.magneticFieldX() << ", "
           << mfr.magneticFieldY() << ", "
           << mfr.magneticFieldZ() << ")";
        cv::putText(Imgs.main, ss.str(), cv::Point(10, 47), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();

        ss << "DistanceReading: " << dr.distance();
        cv::putText(Imgs.main, ss.str(), cv::Point(10, 63), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();

        // tick count
        ss << "TickCount: " << cv::getTickCount();
        cv::putText(Imgs.main, ss.str(), cv::Point(10, 79), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();

        // Cropped image frame (only ned a small slice the rest is noice)
        Imgs.fr_cropped = Imgs.main(roi);
        // Blur the input image data
        cv::blur(Imgs.fr_cropped, Imgs.img_blur, cv::Size(7, 7));
        // convert bgr to hsv
        cv::cvtColor(Imgs.img_blur, Imgs.img_hsv, cv::COLOR_BGR2HSV);
        // segment blue
        cv::inRange(Imgs.img_hsv, blue.low, blue.high, Imgs.fr_hsv);
        cv::findContours(Imgs.fr_hsv, b_pts, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE, cv::Point());
        // segment yello
        cv::inRange(Imgs.img_hsv, yellow.low, yellow.high, Imgs.fr_hsv);
        cv::findContours(Imgs.fr_hsv, y_pts, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE, cv::Point());

        // get the ending frame tick count -> performance calculation
        uint64_t end_f = cv::getTickCount();
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
