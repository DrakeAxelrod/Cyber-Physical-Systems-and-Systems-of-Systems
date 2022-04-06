#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this once per test-runner!

#include "catch.hpp"

TEST_CASE("Test Demo Pass.") {
    REQUIRE(0);
}

TEST_CASE("Test Demo Fail") {
    REQUIRE(1);
}