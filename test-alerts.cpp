#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

TEST_CASE("infers the breach according to limits - TOO LOW") {
  REQUIRE(inferBreach(12, 20, 30) == TOO_LOW);
}

TEST_CASE("infers the breach according to limits - TOO HIGH") {
  REQUIRE(inferBreach(32, 20, 30) == TOO_HIGH);
}

TEST_CASE("infers the breach according to limits - NORMAL") {
  REQUIRE(inferBreach(22, 20, 30) == NORMAL);
}

TEST_CASE("classift temperate breach - PASSIVE_COOLING - TOO_HIGH") {
  REQUIRE(classifyTemperatureBreach(PASSIVE_COOLING, 36) == TOO_HIGH);
}

TEST_CASE("classift temperate breach - HI_ACTIVE_COOLING - TOO_HIGH") {
  REQUIRE(classifyTemperatureBreach(HI_ACTIVE_COOLING, 46) == TOO_HIGH);
}

TEST_CASE("classift temperate breach - MED_ACTIVE_COOLING - TOO_HIGH") {
  REQUIRE(classifyTemperatureBreach(MED_ACTIVE_COOLING, 41) == TOO_HIGH);
}
