//
// Created by LMF319018 on 16/01/2019.
//

#include "NamedEntityWord.h"

NamedEntityWord::NamedEntityWord(string name, NamedEntityType namedEntityType) : Word(move(name)) {
    this->namedEntityType = namedEntityType;
}

NamedEntityType NamedEntityWord::getNamedEntityType() {
    return namedEntityType;
}
