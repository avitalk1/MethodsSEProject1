#include "Component.h"

Component::Component(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color, Border border = NONE) {
    if (border == NONE){
        this->setWidth(w);
        this->setHeight(h);
        this->setCoordinate(start_coord);
    }
    else {
        this->setWidth(w+2);
        this->setHeight(h+2);
        this->setCoordinate({start_coord.X+1,start_coord.Y+1});
    }

    this->setBackgroundColor(bg_color);
    this->setTextColor(txt_color);
    this->outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    this->setBorder(border);
}
void Component::drawBorder(){
    int i=0,j=0;
    int w= this->getWidth();
    int h=this->getHeight();
    auto outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(outHandle, this->text_color|this->background_color);
    if(border!=NONE){
        
        char border_line_y , border_line_x,border_topRight_corner,border_bottomRight_corner,border_topLeft_corner,border_bottomLeft_corner;
        if(border==SINGLE_LINE){
            border_line_y='│';
            border_line_x='─';
            border_topLeft_corner='┌';
            border_topRight_corner='┐';
            border_bottomLeft_corner='└';
            border_bottomRight_corner='	┘';
        }
        else{
            border_line_y='║';
            border_line_x='═';
            border_topLeft_corner='╔';
            border_topRight_corner='╗';
            border_bottomLeft_corner='╚';
            border_bottomRight_corner='	╝';
        }
        COORD topLeft ,bottomLeft;
        topLeft={this->start_coordinate.X-1,this->start_coordinate.Y-1};
        bottomLeft={topLeft.X,topLeft.Y+this->getHeight()-1};
        SetConsoleCursorPosition(outHandle, topLeft);
        cout<<border_topLeft_corner;
        for(i=1;i<w-1;i++){
            cout<<border_line_x;
        }
        cout<<border_topRight_corner;
        COORD height_left,height_right;
        height_left={topLeft.X,topLeft.Y+1};
        height_right={height_left.X+w-1,height_left.Y};
        
        for(i=1;i<h-1;i++){
           SetConsoleCursorPosition(outHandle, height_left);
            cout<<border_line_y;
            SetConsoleCursorPosition(outHandle, height_right);
            cout<<border_line_y;
            height_left={height_left.X,height_left.Y+1};
            height_right={height_right.X,height_right.Y+1};
        }
        SetConsoleCursorPosition(outHandle, bottomLeft);
        cout<<border_bottomLeft_corner;
        for(i=1;i<w-1;i++){
            cout<<border_line_x;
        }
        cout<<border_bottomRight_corner;
        h=h-2;
        w=w-2;
    }
    COORD background_line=this->start_coordinate;
    
    for(i=0;i<h;i++){
        SetConsoleCursorPosition(outHandle, background_line);
        for(j=0;j<w;j++){
            cout<<' ';
        }
        background_line={background_line.X,background_line.Y+1};
    }
    CONSOLE_CURSOR_INFO info = {1, 0};
    SetConsoleCursorInfo(outHandle, &info);
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
