#include "Button.h"
Button::Button(COORD start_coord, DWORD bg_color, DWORD txt_color,Component* comp, Listener* listener, Border border,std::string txt,int h,int w):Component(w,h,start_coord,bg_color,txt_color,border)
{
    setLabel(txt);
    this->component=comp;
    this->listener=listener;
}

void Button::pushButton(){
    this->listener->listener(this->component);
}
void Button::eventListener(char T){
    if(0x20==T){
        pushButton();
    }
}
void Button::_draw(){
    this->drawBorder();
    this->label->_draw();
    SetConsoleCursorPosition(outHandle, this->start_coordinate);
}
void Button::setListener(Listener* listener){
    this->listener=listener;
}
Listener* Button::getListener(){
    return this->listener;
}
void Button::setLabel(string button_label){
    if(this->label){
       this->label->setText(button_label);
    }
    else{
    COORD label_coord= this->getCoordinate();
    if(this->height-1>2){
        label_coord={label_coord.X,label_coord.Y+this->height/2};
    }
    if(this->width - button_label.length() > 1){
        label_coord={label_coord.X+(this->width - button_label.length())/2,label_coord.Y};
    }
    
    this->label=new Label(label_coord,this->background_color,this->text_color,button_label,border);

    }
   }
Label* Button::getLabel(){
    return this->label;
}
Button::~Button(){
    delete(this->label);
    delete(this->listener);
}