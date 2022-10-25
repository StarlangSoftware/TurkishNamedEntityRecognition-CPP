//
// Created by LMF319018 on 16/01/2019.
//

#include "NamedEntityWord.h"

/**
 * A constructor of {@link NamedEntityWord} which takes name and nameEntityType as input and sets the corresponding attributes
 * @param name Name of the word
 * @param namedEntityType {@link NamedEntityType} of the word
 */
NamedEntityWord::NamedEntityWord(const string& name, NamedEntityType namedEntityType) : Word(name) {
    this->namedEntityType = namedEntityType;
}

/**
 * Accessor method for namedEntityType attribute.
 *
 * @return namedEntityType of the word.
 */
NamedEntityType NamedEntityWord::getNamedEntityType() const{
    return namedEntityType;
}
