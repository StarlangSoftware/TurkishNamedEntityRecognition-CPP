//
// Created by LMF319018 on 16/01/2019.
//

#ifndef NAMEDENTITYRECOGNITION_GAZETTEER_H
#define NAMEDENTITYRECOGNITION_GAZETTEER_H

#include <string>
#include <unordered_set>
using namespace std;

class Gazetteer {
private:
    unordered_set<string> data;
    string name;
public:
    Gazetteer(const string& name, const string& fileName);
    string getName() const;
    bool contains(const string& word) const;
};


#endif //NAMEDENTITYRECOGNITION_GAZETTEER_H
