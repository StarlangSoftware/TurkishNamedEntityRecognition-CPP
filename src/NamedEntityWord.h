//
// Created by LMF319018 on 16/01/2019.
//

#ifndef NAMEDENTITYRECOGNITION_NAMEDENTITYWORD_H
#define NAMEDENTITYRECOGNITION_NAMEDENTITYWORD_H


#include <Word.h>
#include "NamedEntityType.h"

class NamedEntityWord : public Word {
private:
    NamedEntityType namedEntityType;
public:
    NamedEntityWord(string name, NamedEntityType namedEntityType);
    NamedEntityType getNamedEntityType();
};


#endif //NAMEDENTITYRECOGNITION_NAMEDENTITYWORD_H
