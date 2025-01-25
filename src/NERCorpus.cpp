//
// Created by Olcay Taner Yıldız on 18.01.2019.
//

#include <fstream>
#include "NERCorpus.h"
#include "NamedEntitySentence.h"
#include "NamedEntityWord.h"

NERCorpus::NERCorpus() = default;

/**
 * A clone method for the NERCorpus class.
 *
 * @return A copy of the current NERCorpus class.
 */
NERCorpus NERCorpus::emptyCopy() const{
    return NERCorpus();
}

/**
 * Another constructor of NERCorpus which takes a fileName of the corpus as an input, reads the
 * corpus from that file.
 *
 * @param fileName Name of the corpus file.
 */
NERCorpus::NERCorpus(const string& fileName) {
    ifstream inputStream;
    inputStream.open(fileName, ifstream::in);
    this->fileName = fileName;
    string line;
    while (inputStream.good()){
        getline(inputStream, line);
        addSentence(new NamedEntitySentence(line));
    }
}

/**
 * addSentence adds a new sentence to the sentences ArrayList
 * @param sentence Sentence to be added.
 */
void NERCorpus::addSentence(NamedEntitySentence* sentence) {
    sentences.emplace_back(sentence);
}

/**
 * writeToFile writes the corpus in the format given above into the file with the given fileName.
 * @param fileName Output file name.
 */
void NERCorpus::writeToFile(const string& fileName) const {
    ofstream output;
    output.open(fileName, ofstream :: out);
    for (Sentence* sentence : sentences){
        for (int i = 0; i < sentence->wordCount(); i++){
            auto* word = (NamedEntityWord*)(sentence->getWord(i));
            switch (word->getNamedEntityType()){
                case NamedEntityType::LOCATION:
                    output << " <b_enamex TYPE=\"LOCATION\">" + word->getName() + "<e_enamex>";
                    break;
                case NamedEntityType::ORGANIZATION:
                    output << " <b_enamex TYPE=\"ORGANIZATION\">" + word->getName() + "<e_enamex>";
                    break;
                case NamedEntityType::PERSON:
                    output << " <b_enamex TYPE=\"PERSON\">" + word->getName() + "<e_enamex>";
                    break;
                case NamedEntityType::TIME:
                    output << " <b_enamex TYPE=\"TIME\">" + word->getName() + "<e_enamex>";
                    break;
                case NamedEntityType::MONEY:
                    output << " <b_enamex TYPE=\"MONEY\">" + word->getName() + "<e_enamex>";
                    break;
                default:
                    output << " " + word->getName();
                    break;
            }
        }
        output << "\n";
    }
    output.close();
}
