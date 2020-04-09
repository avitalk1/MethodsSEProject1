#include "Label.h"

Label::Label(std::string value, COORD coord) : value(value), coord(coord) {}

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

void Label::setColors(DWORD fc , DWORD bc){
    this->colors = fc | bc;
}

DWORD Label::getColors(){
    return this->colors;
}

void Label::draw(){
    auto outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(outHandle,coord);
    SetConsoleTextAttribute(outHandle,colors);
    std::cout<< value;

    CONSOLE_CURSOR_INFO info ={1,0};
    SetConsoleCursorInfo(outHandle,&info);
}