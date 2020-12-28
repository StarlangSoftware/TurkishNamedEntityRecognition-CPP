//
// Created by Olcay Taner YILDIZ on 28.12.2020.
//

#include <CounterHashMap.h>
#include "catch.hpp"
#include "../NERCorpus.h"
#include "../NamedEntityType.h"
#include "../NamedEntityWord.h"

TEST_CASE("NERCorpusTest-testNERCorpus") {
    CounterHashMap<NamedEntityType> counter = CounterHashMap<NamedEntityType>();
    NERCorpus nerCorpus = NERCorpus("nerdata.txt");
    REQUIRE(27556 == nerCorpus.sentenceCount());
    REQUIRE(492233 == nerCorpus.numberOfWords());
    for (int i = 0; i < nerCorpus.sentenceCount(); i++){
        auto* namedEntitySentence = (NamedEntitySentence*) nerCorpus.getSentence(i);
        for (int j = 0; j < namedEntitySentence->wordCount(); j++){
            auto* namedEntityWord = (NamedEntityWord*) namedEntitySentence->getWord(j);
            counter.put(namedEntityWord->getNamedEntityType());
        }
    }
    REQUIRE(438976 == counter[NamedEntityType::NONE]);
    REQUIRE(23878 == counter[NamedEntityType::PERSON]);
    REQUIRE(16931 == counter[NamedEntityType::ORGANIZATION]);
    REQUIRE(12448 == counter[NamedEntityType::LOCATION]);
}