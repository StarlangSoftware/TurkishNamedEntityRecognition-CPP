//
// Created by LMF319018 on 16/01/2019.
//

#include <fstream>
#include "Dictionary/Word.h"
#include "Gazetteer.h"

/**
 * A constructor for a specific gazetteer. The constructor takes name of the gazetteer and file name of the
 * gazetteer as input, reads the gazetteer from the input file.
 * @param name Name of the gazetteer. This name will be used in programming to separate different gazetteers.
 * @param fileName File name of the gazetteer data.
 */
Gazetteer::Gazetteer(const string& name, const string& fileName) {
    this->name = name;
    string word;
    ifstream inputStream;
    inputStream.open(fileName, ifstream::in);
    while (inputStream.good()){
        getline(inputStream, word);
        data.emplace(word);
    }
    inputStream.close();
}

/**
 * Accessor method for the name of the gazetteer.
 * @return Name of the gazetteer.
 */
string Gazetteer::getName() const{
    return name;
}

/**
 * The most important method in Gazetteer class. Checks if the given word exists in the gazetteer. The check
 * is done in lowercase form.
 * @param word Word to be search in Gazetteer.
 * @return True if the word is in the Gazetteer, False otherwise.
 */
bool Gazetteer::contains(const string& word) const {
    string lowerCase = Word::toLowerCase(word);
    return data.contains(lowerCase);
}
