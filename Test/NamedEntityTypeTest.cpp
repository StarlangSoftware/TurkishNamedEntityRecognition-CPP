//
// Created by Olcay Taner YILDIZ on 11.02.2021.
//

#include "catch.hpp"
#include "../src/NamedEntityType.h"

TEST_CASE("NamedEntityTypeTest-testNamedEntityType") {
    REQUIRE(getNamedEntityType("person") == NamedEntityType::PERSON);
    REQUIRE(getNamedEntityType("Time") == NamedEntityType::TIME);
    REQUIRE(getNamedEntityType("location") == NamedEntityType::LOCATION);
}