//
// Created by Olcay Taner YILDIZ on 23.02.2021.
//

#include "catch.hpp"
#include "../src/Slot.h"

TEST_CASE("SlotTest-testSlot") {
    Slot slot1 = Slot("B-depart_date.month_name");
    REQUIRE(SlotType::B == slot1.getType());
    REQUIRE("depart_date.month_name" == slot1.getTag());
    REQUIRE("B-depart_date.month_name" == slot1.to_string());
    Slot slot2 = Slot("O");
    REQUIRE(SlotType::O == slot2.getType());
    REQUIRE("O" == slot2.to_string());
    Slot slot3 = Slot("I-round_trip");
    REQUIRE(SlotType::I == slot3.getType());
    REQUIRE("round_trip" == slot3.getTag());
    REQUIRE("I-round_trip" == slot3.to_string());
}