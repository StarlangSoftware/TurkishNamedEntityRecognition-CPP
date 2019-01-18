//
// Created by Olcay Taner Yıldız on 18.01.2019.
//

#ifndef NAMEDENTITYRECOGNITION_NAMEDENTITYSENTENCE_H
#define NAMEDENTITYRECOGNITION_NAMEDENTITYSENTENCE_H


#include <Sentence.h>

class NamedEntitySentence : public Sentence{
public:
    NamedEntitySentence();
    NamedEntitySentence(string sentence);
};


#endif //NAMEDENTITYRECOGNITION_NAMEDENTITYSENTENCE_H
