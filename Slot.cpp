//
// Created by Olcay Taner YILDIZ on 23.02.2021.
//

#include "Slot.h"

Slot::Slot(SlotType type, string tag) {
    this->tag = tag;
    this->type = type;
}

Slot::Slot(string slot) {
    if (slot == "O" || slot == "o"){
        this->type = SlotType::O;
        this->tag = "";
    } else {
        string type = slot.substr(0, slot.find_first_of('-'));
        string tag = slot.substr(slot.find_first_of('-') + 1);
        if (type == "B"){
            this->type = SlotType::B;
        } else {
            this->type = SlotType::I;
        }
        this->tag = tag;
    }
}

string Slot::getTag() {
    return tag;
}

string Slot::to_string() {
    if (type == SlotType::O){
        return "O";
    } else {
        if (type == SlotType::B){
            return "B-" + tag;
        } else {
            return "I-" + tag;
        }
    }
}

SlotType Slot::getType() {
    return type;
}
