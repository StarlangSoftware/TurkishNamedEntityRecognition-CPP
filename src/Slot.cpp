//
// Created by Olcay Taner YILDIZ on 23.02.2021.
//

#include "Slot.h"

Slot::Slot(SlotType type, const string& tag) {
    this->tag = tag;
    this->type = type;
}

Slot::Slot(const string& slot) {
    if (slot == "O" || slot == "o"){
        this->type = SlotType::O;
        this->tag = "";
    } else {
        string _type = slot.substr(0, slot.find_first_of('-'));
        string _tag = slot.substr(slot.find_first_of('-') + 1);
        if (_type == "B"){
            this->type = SlotType::B;
        } else {
            this->type = SlotType::I;
        }
        this->tag = _tag;
    }
}

string Slot::getTag() const{
    return tag;
}

string Slot::to_string() const{
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

SlotType Slot::getType() const{
    return type;
}
