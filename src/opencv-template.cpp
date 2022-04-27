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
    const std::string NAME{ commandlineArguments["name"] };
    const uint32_t WIDTH{ static_cast<uint32_t>(std::stoi(commandlineArguments["width"])) };
    const uint32_t HEIGHT{ static_cast<uint32_t>(std::stoi(commandlineArguments["height"])) };
    const bool VERBOSE{commandlineArguments.count("verbose") != 0};

    // Attach to the shared memory.
    std::unique_ptr<cluon::SharedMemory> sharedMemory{new cluon::SharedMemory{NAME}};
    if (sharedMemory && sharedMemory->valid())
    {
      std::clog << argv[0] << ": Attached to shared memory '"
                << sharedMemory->name() << " (" << sharedMemory->size()
                << " bytes)." << std::endl;

      // Interface to a running OpenDaVINCI session where network messages are
      // exchanged. The instance od4 allows you to send and receive messages.
      cluon::OD4Session od4{ static_cast<uint16_t>(std::stoi(commandlineArguments["cid"])) };


      // Get the steering angle request
      opendlv::proxy::GroundSteeringRequest gsr;
      std::mutex gsrMutex;
      auto onGroundSteeringRequest = [&gsr, &gsrMutex](cluon::data::Envelope &&env)
      {
        std::lock_guard<std::mutex> lck(gsrMutex);
        gsr = cluon::extractMessage<opendlv::proxy::GroundSteeringRequest>(std::move(env));
        std::cout << "lambda: groundSteering = " << gsr.groundSteering() << std::endl;
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

      // // direction perception
      // opendlv::logic::perception::ObjectDirection od;
      // std::mutex odMutex;
      // auto getObjectDirection = [&od, &odMutex](cluon::data::Envelope &&env)
      // {
      //   std::lock_guard<std::mutex> lck(odMutex);
      //   od = cluon::extractMessage<opendlv::logic::perception::ObjectDirection>(std::move(env));
      // };
      // od4.dataTrigger(opendlv::logic::perception::ObjectDirection::ID(), getObjectDirection);

      // // get angle reading
      // opendlv::proxy::AngleReading ar;
      // std::mutex arMutex;
      // auto getAngleReading = [&ar, &arMutex](cluon::data::Envelope &&env)
      // {
      //   std::lock_guard<std::mutex> lck(arMutex);
      //   ar = cluon::extractMessage<opendlv::proxy::AngleReading>(std::move(env));
      // };
      // od4.dataTrigger(opendlv::proxy::AngleReading::ID(), getAngleReading);
      
      // opendlv::logic::sensation::Geolocation gl;
      // std::mutex glMutex;
      // auto getGeolocation = [&gl, &glMutex](cluon::data::Envelope &&env)
      // {
      //   std::lock_guard<std::mutex> lck(glMutex);
      //   gl = cluon::extractMessage<opendlv::logic::sensation::Geolocation>(std::move(env));
      // };
      // od4.dataTrigger(opendlv::logic::sensation::Geolocation::ID(), getGeolocation);


      // opendlv::logic::sensation::Equilibrioception ee;
      // std::mutex eeMutex;
      // auto getEquilibrioception = [&ee, &eeMutex](cluon::data::Envelope &&env)
      // {
      //   std::lock_guard<std::mutex> lck(eeMutex);
      //   ee = cluon::extractMessage<opendlv::logic::sensation::Equilibrioception>(std::move(env));
      // };
      // od4.dataTrigger(opendlv::logic::sensation::Equilibrioception::ID(), getEquilibrioception);

      // opendlv::proxy::PulseWidthModulationRequest pwm;
      // std::mutex pwmMutex;
      // auto getPulseWidthModulationRequest = [&pwm, &pwmMutex](cluon::data::Envelope &&env)
      // {
      //   std::lock_guard<std::mutex> lck(pwmMutex);
      //   pwm = cluon::extractMessage<opendlv::proxy::PulseWidthModulationRequest>(std::move(env));
      // };
      // od4.dataTrigger(opendlv::proxy::PulseWidthModulationRequest::ID(), getPulseWidthModulationRequest);

      // Endless loop; end the program by pressing Ctrl-C.
      while (od4.isRunning())
      {
        // OpenCV data structure to hold an image.
        cv::Mat img;
        // buffer for timestamp string
        char buffer[60];
        // miscroseconds timestamp (utc)
        uint64 thistime;
        std::stringstream ss;
        // Lock the shared memory.
        sharedMemory->lock();
        {   // Copy the pixels from the shared memory into our own data structure.
            cv::Mat wrapped(HEIGHT, WIDTH, CV_8UC4, sharedMemory->data());
            img = wrapped.clone();
            // Code to show the current timestamp
            time_t epoch = (cluon::time::now()).seconds();
            strftime(buffer, 60, "%Y-%m-%dT%H:%M:%SZ", gmtime(&epoch));
            thistime = cluon::time::toMicroseconds((sharedMemory->getTimeStamp()).second);
        }
        sharedMemory->unlock();
        ss << "TimeStamp: " << thistime;
        cv::putText(img, ss.str(), cv::Point(10, 15), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();

        ss << "GroundSteering: " << gsr.groundSteering();
        cv::putText(img, ss.str(), cv::Point(10, 31), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();

        ss << "MagneticField (x,y,z): " << "("
           << mfr.magneticFieldX() << ", "
           << mfr.magneticFieldY() << ", "
           << mfr.magneticFieldZ() << ")";
        cv::putText(img, ss.str(), cv::Point(10, 47), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();

        ss << "DistanceReading: " << dr.distance();
        cv::putText(img, ss.str(), cv::Point(10, 63), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        ss.str("");
        ss.clear();

        // ss << "ObjectDirection: azimuth:" << od.azimuthAngle() << ", zenith:" << od.zenithAngle();
        // cv::putText(img, ss.str(), cv::Point(10, 79), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        // ss.str("");
        // ss.clear();

        // ss << "AngleReading: " << ar.angle();
        // cv::putText(img, ss.str(), cv::Point(10, 95), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        // ss.str("");
        // ss.clear();

        // ss << "Geolocation: lon:" << gl.latitude() << ", lat:" << gl.longitude();
        // cv::putText(img, ss.str(), cv::Point(10, 111), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        // ss.str("");
        // ss.clear();

        // ss << "Equilibrioception: pitch:" << ee.pitchRate() 
        //    << ", yaw:" << ee.yawRate() << ", roll:" << ee.rollRate()
        //    << ", vx:" << ee.vx() << ", vy:" << ee.vy() << ", vz:" << ee.vz();
        // cv::putText(img, ss.str(), cv::Point(10, 127), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        // ss.str("");
        // ss.clear();

        // ss << "PWM(duty cycles): " << pwm.dutyCycleNs() << " ns";
        // cv::putText(img, ss.str(), cv::Point(10, 143), cv::FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255), 1);
        // ss.str("");
        // ss.clear();

        if (VERBOSE)
        {
          cv::imshow(sharedMemory->name().c_str(), img);
          cv::waitKey(1);
        }
      }
    }
    retCode = 0;
  }
  return retCode;
}
