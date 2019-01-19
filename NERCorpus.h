//
// Created by Olcay Taner Yıldız on 18.01.2019.
//

#ifndef NAMEDENTITYRECOGNITION_NERCORPUS_H
#define NAMEDENTITYRECOGNITION_NERCORPUS_H


#include <Corpus.h>
#include "NamedEntitySentence.h"

class NERCorpus : public Corpus{
public:
    NERCorpus();
    NERCorpus emptyCopy();
    NERCorpus(string fileName);
    void addSentence(NamedEntitySentence* sentence);
    void writeToFile(string fileName);
};


#endif //NAMEDENTITYRECOGNITION_NERCORPUS_H
