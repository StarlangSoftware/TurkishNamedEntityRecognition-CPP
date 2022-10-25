//
// Created by Olcay Taner YILDIZ on 23.02.2021.
//

#ifndef NAMEDENTITYRECOGNITION_SLOT_H
#define NAMEDENTITYRECOGNITION_SLOT_H


#include "SlotType.h"
#include <string>
using namespace std;

class Slot {
private:
    SlotType type;
    string tag;
public:
    Slot(SlotType type, const string& tag);
    explicit Slot(const string& slot);
    string getTag() const;
    SlotType getType() const;
    string to_string() const;
};


#endif //NAMEDENTITYRECOGNITION_SLOT_H
