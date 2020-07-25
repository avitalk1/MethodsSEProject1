#include "Component.h"
Component::Component(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color,HANDLE outHandle, Border border = NONE) {
    this->setWidth(w);
    this->setHeight(h);
    this->setCoordinate(start_coord);
    this->setBackgroundColor(bg_color);
    this->setTextColor(txt_color);
    this->outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    this->setBorder(border);
}
void  Component::setCoordinate(COORD coord){
    this->start_coordinate = coord;
}
COORD Component::getCoordinate(){
    return this->start_coordinate;
}
COORD Component::currentLocation(){
    return this->start_coordinate;
}
void Component::setBackgroundColor(DWORD color){
    this->background_color = color;
}
void Component::setTextColor(DWORD color){
    this->text_color = color;
}
DWORD Component::getBackgroundColor(){
    return this->background_color;
}
DWORD Component::getTextColor(){
    return this->text_color;
}
void Component::setHeight(int h){
    this->height = h;
}
void Component::setWidth(int w){
    this->width = w;
}
int Component::getHeight(){
    return this->height;
}
int Component::getWidth(){
    return this->width;
}
void Component::setBorder(Border b){
    this->border = b;
}
Border Component::getBorder(){
    return this->border;
}
