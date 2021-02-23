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
    Slot(SlotType type, string tag);
    explicit Slot(string slot);
    string getTag();
    SlotType getType();
    string to_string();
};


#endif //NAMEDENTITYRECOGNITION_SLOT_H
