#include "Button.h"
Button::Button(COORD start_coord, DWORD bg_color, DWORD txt_color,Component* comp, Listener* listener, Border border,std::string txt,int h,int w):Component(w,h,start_coord,bg_color,txt_color,border)
{
    this->label=NULL;
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
    WORD prevAttribute;
    _CONSOLE_SCREEN_BUFFER_INFO bi;
    GetConsoleScreenBufferInfo(outHandle, &bi);
    prevAttribute = bi.wAttributes;
    this->drawBorder();
    this->label->_draw();
    CONSOLE_CURSOR_INFO info = {1, 1};
    SetConsoleTextAttribute(outHandle, prevAttribute);      //set colors back to prev
    SetConsoleCursorPosition(outHandle, this->start_coordinate);
}
void Button::setListener(Listener* listener){
    this->listener=listener;
}
Listener* Button::getListener(){
    return this->listener;
}
void Button::setBackgroundColor(DWORD color){
    this->label->setBackgroundColor(color);
    this->background_color=color;
}
void Button::setLabel(string button_label){
    if(this->label){
       this->label->setText(button_label);
    }
    else{
    COORD label_coord= this->getCoordinate();
    if (this->border!=NONE) {
        label_coord={label_coord.X-1,label_coord.Y-1};
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