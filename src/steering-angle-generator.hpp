#ifndef STEERING_ANGLE_GENERATOR_HPP
#define STEERING_ANGLE_GENERATOR_HPP

// Include the single-file, header-only middleware libcluon to create
// high-performance microservices
#include "cluon-complete.hpp"
// Include the OpenDLV Standard Message Set that contains messages that are
// usually exchanged for automotive or robotic applications
#include "opendlv-standard-message-set.hpp"

// Include the GUI and image processing header files from OpenCV
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <chrono>
#include <string>
#include <time.h>

/**
 * @brief the primary function to return the computed steering angle
 * 
 */
void steer();

/**
 * @brief your a wizard, you can do magic here
 * 
 */
void do_magic();

#endif // STEERING_ANGLE_GENERATOR_HPP
