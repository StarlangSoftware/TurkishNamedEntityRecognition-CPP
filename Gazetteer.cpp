//
// Created by LMF319018 on 16/01/2019.
//

#include <fstream>
#include "Gazetteer.h"

Gazetteer::Gazetteer(string name, string fileName) {
    this->name = move(name);
    string word;
    ifstream inputStream;
    inputStream.open("fileName", ifstream::in);
    while (inputStream.good()){
        getline(inputStream, word);
        data.emplace(word);
    }
    inputStream.close();
}

string Gazetteer::getName() {
    return name;
}

bool Gazetteer::contains(string word) {
    return data.find(word) != data.end();
}
