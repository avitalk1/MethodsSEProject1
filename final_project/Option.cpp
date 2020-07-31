#include "Option.h"

Option::Option(string label, DWORD txt_color, DWORD bg_color,COORD start_coord ){
    this->setTextColor(txt_color);
    this->setBackgroundColor(background_color);
    this->setCoordinate(start_coord);
    this->outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    this->is_selected=false;
}
// void Option::setSelected(bool T){
//     this->is_selected=T;
// }
bool Option::getIsSelected(){
    return this->is_selected;
}

void Option::setCoordinate(COORD coord){
    this->coordinate = coord;

}
COORD Option::getCoordinate(){
    return this->coordinate;
}

void Option::setBackgroundColor(DWORD color){
    this->background_color = color;
}
void Option::setTextColor(DWORD color){
    this->text_color = color;
}
DWORD Option::getBackgroundColor(){
    return this->background_color;
}
DWORD Option::getTextColor(){
    return this->text_color;
}

Option::~Option(){
    
}