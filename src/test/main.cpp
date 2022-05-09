#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this once per test-runner!

#include "catch.hpp"
#include "steering-angle-generator.hpp"

TEST_CASE("Test the Bound class", "[steering-angle-generator]") {
  Bound<int> b = Bound<int>(0, 10);
  REQUIRE(b.low == 0);
  REQUIRE(b.high == 10);
}

TEST_CASE("Test the HSVBounds class", "[steering-angle-generator]") {
  HSVBounds b = HSVBounds(0, 180, 0, 255, 0, 255);
  REQUIRE(b.h.low == 0);
  REQUIRE(b.h.high == 180);
  REQUIRE(b.s.low == 0);
  REQUIRE(b.s.high == 255);
  REQUIRE(b.v.low == 0);
  REQUIRE(b.v.high == 255);
}

TEST_CASE("do_magic returns correct steering angle",
          "[steering-angle-generator]") {
  int val = do_magic();
  REQUIRE(val == 0);
}

TEST_CASE("steer returns correct steering angle",
          "[steering-angle-generator]") {
  int val = steer();
  REQUIRE(val == 0);
}

TEST_CASE("turn_in_timestamp creates a valid timestamp",
          "[steering-angle-generator]") {
  std::pair<bool, cluon::data::TimeStamp> ts =
      std::pair<bool, cluon::data::TimeStamp>(true, cluon::data::TimeStamp());
  std::string timestamp = turn_in_timestamp(ts, 0);
  //std:string::compare(timestamp, "group_05;00;0");
  REQUIRE(timestamp == "group_05;00;0");
}
