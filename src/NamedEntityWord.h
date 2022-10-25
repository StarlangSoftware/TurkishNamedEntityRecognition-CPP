//
// Created by LMF319018 on 16/01/2019.
//

#ifndef NAMEDENTITYRECOGNITION_NAMEDENTITYWORD_H
#define NAMEDENTITYRECOGNITION_NAMEDENTITYWORD_H


#include "Dictionary/Word.h"
#include "NamedEntityType.h"

class NamedEntityWord : public Word {
private:
    NamedEntityType namedEntityType;
public:
    NamedEntityWord(const string& name, NamedEntityType namedEntityType);
    NamedEntityType getNamedEntityType() const;
};


#endif //NAMEDENTITYRECOGNITION_NAMEDENTITYWORD_H
