#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this once per test-runner!

#include "catch.hpp"
#include "SensorReading.hpp"

TEST_CASE("Test Addition") {
    SensorReading Test;
    REQUIRE(Test.Addition(4,5) == 9);
}

TEST_CASE("Test Multiplication") {
    SensorReading Test;
    REQUIRE(Test.Multiply(1,2) == 2);
}