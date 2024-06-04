//
// Created by Olcay Taner YILDIZ on 23.02.2021.
//

#include "Slot.h"

/**
 * Constructor for the Slot object. Slot object stores the information about more specific entities. The slot
 * type represents the beginning, inside or outside the slot, whereas tag represents the entity tag of the
 * slot.
 * @param type Type of the slot. B, I or O for beginning, inside, outside the slot respectively.
 * @param tag Tag of the slot.
 */
Slot::Slot(SlotType type, const string& tag) {
    this->tag = tag;
    this->type = type;
}

/**
 * Second constructor of the slot for a given slot string. A Slot string consists of slot type and slot tag
 * separated with '-'. For example B-Person represents the beginning of a person. For outside tagging simple 'O' is
 * used.
 * @param slot Input slot string.
 */
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

/**
 * Accessor for the type of the slot.
 * @return Type of the slot.
 */
SlotType Slot::getType() const{
    return type;
}

/**
 * Accessor for the tag of the slot.
 * @return Tag of the slot.
 */
string Slot::getTag() const{
    return tag;
}

/**
 * to_string method of the slot.
 * @return Type and tag separated with '-'. If the type is outside, it returns 'O'.
 */
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
