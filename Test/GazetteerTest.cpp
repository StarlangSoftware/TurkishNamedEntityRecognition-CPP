//
// Created by Olcay Taner YILDIZ on 28.12.2020.
//

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../Gazetteer.h"

TEST_CASE("GazetteerTest-testContains") {
    Gazetteer gazetteer = Gazetteer("location", "gazetteer-location.txt");
    REQUIRE_FALSE(!gazetteer.contains("bağdat"));
    REQUIRE_FALSE(!gazetteer.contains("BAĞDAT"));
    REQUIRE_FALSE(!gazetteer.contains("belçika"));
    REQUIRE_FALSE(!gazetteer.contains("BELÇİKA"));
    REQUIRE_FALSE(!gazetteer.contains("körfez"));
    REQUIRE_FALSE(!gazetteer.contains("KÖRFEZ"));
    REQUIRE_FALSE(!gazetteer.contains("küba"));
    REQUIRE_FALSE(!gazetteer.contains("KÜBA"));
    REQUIRE_FALSE(!gazetteer.contains("varşova"));
    REQUIRE_FALSE(!gazetteer.contains("VARŞOVA"));
    REQUIRE_FALSE(!gazetteer.contains("krallık"));
    REQUIRE_FALSE(!gazetteer.contains("KRALLIK"));
    REQUIRE_FALSE(!gazetteer.contains("berlin"));
    REQUIRE_FALSE(!gazetteer.contains("BERLİN"));
}