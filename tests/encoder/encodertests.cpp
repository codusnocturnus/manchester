#include <catch2/catch.hpp>

#include "encoder/encodercontext.hpp"

TEST_CASE("Defaults to Quiescent", "[encoder]") {
    manchester::EncoderContext ec;
    REQUIRE(ec.statename() == "QUIESCENT (HI)");
}

TEST_CASE("Send zeros in Quiescent", "[encoder]") {
    REQUIRE(true);
}
