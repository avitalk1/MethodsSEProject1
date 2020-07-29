
#include "CheckedOption.h"
/*
    init checked option
    init option
    set label in checkedoption constructor
    build wmpty button in checked option constructor
*/
 void CheckedOption::drawOption(){
    this->button->_draw();
    this->label->_draw();
 }
CheckedOption::CheckedOption(string label, DWORD txt_color, DWORD bg_color,COORD coord)
:Option(label,txt_color,bg_color,coord){
    this->label=new Label({coord.X+2,coord.Y},bg_color,txt_color,label);
    this->button= new Button(coord,  BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED,FOREGROUND_GREEN | FOREGROUND_INTENSITY,NULL,NULL);    
}
/*
set label of the option
*/
void CheckedOption::setLabel(string label){

}
/*
    this is a toggle function 
    first:
        if is_selected == true 
            chenage it to false 
        if is_selected == false 
            change it to true
    second 
        if is selected == true 
            change the label of the button to V
        if is selected == false 
            change remove the label from the button
*/
void CheckedOption::setIsSelected(){
    Label* label=this->button->getLabel();
    if(label->getText()==" "){
        label->setText("V");
    }
    else{
        label->setText(" ");
    }
    this->button->_draw();
}
CheckedOption::~CheckedOption(){
    delete(this->button);
    delete(this->label);
}
