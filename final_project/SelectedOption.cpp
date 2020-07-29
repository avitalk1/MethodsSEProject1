#include "SelectedOption.h"
/*
    init the inherited option class
    in the selected option constructor 
        creatre a button with the label passed in the function
*/
SelectedOption::SelectedOption(COORD start_coord, string label, DWORD txt_color, DWORD bg_color):Option(label, txt_color,bg_color, start_coord){}

/*
    ???
    basically what should happen if the button of this option is clickec is:
    we should take the label from the button and display it in the combo box label 
*/
void SelectedOption::setIsSelected(){
    this->is_selected = true;
}
SelectedOption::~SelectedOption(){}
