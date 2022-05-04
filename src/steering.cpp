#include "steering-angle-generator.hpp"

void steer()
{
  do_magic();
}

void do_magic()
{
}

std::string get_timestamp(std::pair<bool, cluon::data::TimeStamp> ts, time_t now)
{
  char buf[60];
  std::stringstream s;
  if (ts.first)
  {
    strftime(buf, 60, "%Y-%m-%dT%H:%M:%SZ", gmtime(&now));
    s << "Now: " << buf << ", ts: "
      << ts.second.seconds() << "."
      << ts.second.microseconds();
  }
  else
  {
    std::stringstream ss;
    s << "No timestamp available.";
  }
  return s.str();
}

void turn_in_timestamp(std::pair<bool, cluon::data::TimeStamp> timestamp, double angle)
{
  if (timestamp.first)
  {
    auto ts = timestamp.second;
    std::cout << "group_05;"
              << ts.seconds()
              << ts.microseconds()
              << ";"
              << angle
              << std::endl;
  }
  else
  {
    std::stringstream ss;
    std::cout << "No timestamp available." << std::endl;
  }
}
