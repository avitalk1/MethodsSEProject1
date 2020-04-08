#include "Label.h"

void Label::setValue(std::string value){
    this->value = value;
}

std::string Label::getValue(){
    return this->value;
}

void Label::setCoord(COORD coord){
    this->coord = coord;
}

COORD Label::getCoord(){
    return this->coord;
}