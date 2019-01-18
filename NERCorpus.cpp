//
// Created by Olcay Taner Yıldız on 18.01.2019.
//

#include <fstream>
#include "NERCorpus.h"
#include "NamedEntitySentence.h"
#include "NamedEntityWord.h"

NERCorpus::NERCorpus() {
}

NERCorpus NERCorpus::emptyCopy() {
    return NERCorpus();
}

NERCorpus::NERCorpus(string fileName) {
    ifstream inputStream;
    inputStream.open(fileName, ifstream::in);
    this->fileName = move(fileName);
    string line;
    while (inputStream.good()){
        getline(inputStream, line);
        addSentence(NamedEntitySentence(line));
    }
}

void NERCorpus::addSentence(NamedEntitySentence sentence) {
    sentences.emplace_back(sentence);
}

void NERCorpus::writeToFile(string fileName) {
    ofstream output;
    output.open(fileName, ofstream :: out);
    for (Sentence sentence : sentences){
        for (int i = 0; i < sentence.wordCount(); i++){
            NamedEntityWord word = (NamedEntityWord) sentence.getWord(i);
            switch (word.getNamedEntityType()){
                case NamedEntityType::LOCATION:
                    output << " <b_enamex TYPE=\"LOCATION\">" + word.getName() + "<e_enamex>";
                    break;
                case NamedEntityType::ORGANIZATION:
                    output << " <b_enamex TYPE=\"ORGANIZATION\">" + word.getName() + "<e_enamex>";
                    break;
                case NamedEntityType::PERSON:
                    output << " <b_enamex TYPE=\"PERSON\">" + word.getName() + "<e_enamex>";
                    break;
                case NamedEntityType::TIME:
                    output << " <b_enamex TYPE=\"TIME\">" + word.getName() + "<e_enamex>";
                    break;
                case NamedEntityType::MONEY:
                    output << " <b_enamex TYPE=\"MONEY\">" + word.getName() + "<e_enamex>";
                    break;
                default:
                    output << " " + word.getName();
                    break;
            }
        }
        output << "\n";
    }
    output.close();
}
