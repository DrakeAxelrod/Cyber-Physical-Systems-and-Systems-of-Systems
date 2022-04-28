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
