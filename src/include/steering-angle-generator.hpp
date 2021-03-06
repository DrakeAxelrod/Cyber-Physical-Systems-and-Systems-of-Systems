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
#include <sstream>
#include <chrono>
#include <string>
#include <time.h>

/**
 * @brief This struct is data object to hold an upper and lower bounds.
 * @details This struct is used to hold an upper and lower bounds.
 * @tparam T The type of the bounds.
 */
template <class T>
class Bound
{
public:
  /**
   * @brief The lower bound.
   * @details The lower bound.
   */
  T low;
  /**
   * @brief The upper bound.
   * @details The upper bound.
   */
  T high;
  /**
   * @brief The constructor.
   * @details The constructor.
   *
   * @param l The lower bound.
   * @param h The upper bound.
   */
  Bound(T l, T h) : low(l), high(h) {}
};

/**
 * @brief This struct is data object to hold an upper and lower bounds for HSV values.
 *
 * @param Bound<int>:h The upper and lower bounds for Hue.
 * @param Bound<int>:s The upper and lower bounds for Saturation.
 * @param Bound<int>:v The upper and lower bounds for Value.
 */
class HSVBounds
{
public:
  /**
   * @brief The upper and lower bounds for Hue.
   * @details The upper and lower bounds for Hue.
   */
  Bound<int> h;
  /**
   * @brief The upper and lower bounds for Saturation.
   * @details The upper and lower bounds for Saturation.
   */
  Bound<int> s;
  /**
   * @brief The upper and lower bounds for Value.
   * @details The upper and lower bounds for Value.
   */
  Bound<int> v;

  /**
   * @brief The constructor.
   * @details The constructor.
   *
   * @param hl The lower bound for Hue.
   * @param hh The upper bound for Hue.
   * @param sl The lower bound for Saturation.
   * @param sh The upper bound for Saturation.
   * @param vl The lower bound for Value.
   * @param vh The upper bound for Value.
   */
  HSVBounds(int hl, int hh, int sl, int sh, int vl, int vh) : h(hl, hh), s(sl, sh), v(vl, vh) {}
};

/**
 * @brief This struct is meant hold all the different image materials
 *
 * @param cv::Mat:main The main image.
 * @param cv::Mat:fr_hsv The filtered image.
 * @param cv::Mat:fr_cropped The cropped image.
 * @param cv::Mat:img_hsv The image in HSV color space.
 * @param cv::Mat:img_blur The image after blurring.
 * @param cv::Mat:img_cropped The image after cropping.
 * @param cv::Mat:hsv_debug The image after HSV filtering.
 */
class Images
{
public:
  cv::Mat main;
  cv::Mat fr_hsv;
  cv::Mat fr_cropped;
  cv::Mat img_hsv;
  cv::Mat img_blur;
  cv::Mat img_cropped;
  cv::Mat hsv_debug;
  // constructor
  Images(){};
};

/**
 * @brief the primary function to return the computed steering angle
 *
 */
int steer();

/**
 * @brief your a wizard, you can do magic here
 *
 */
int do_magic();

/**
 * @brief returns the timestamp of the current frame
 *
 * @param ts
 * @param now
 * @return std::string
 */
std::string get_timestamp(std::pair<bool, cluon::data::TimeStamp>, time_t);

/**
 * @brief the final turn-in console print timestamp
 *
 * @param timestamp
 * @param angle
 */
std::string turn_in_timestamp(std::pair<bool, cluon::data::TimeStamp>, double);

int sendData(std::string msg);
int error(std::string msg);

#endif // STEERING_ANGLE_GENERATOR_HPP
