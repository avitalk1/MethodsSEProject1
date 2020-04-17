

#include "comp.h"
comp::comp() {
    this->outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

void comp::setCoord(COORD coord) {
    this->coord = coord;
}
COORD  comp::getCoord() { return this->coord; }

void comp::setColors(DWORD fg, DWORD bg) {
    this->colors = fg | bg;
}
DWORD comp::getColors() {
    return this->colors;
}

COORD  comp::CurrLocation() { return this->coord; }

