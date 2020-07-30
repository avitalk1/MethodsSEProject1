
#include "ComboBox.h"
ComboBox::ComboBox(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color, string head_line, string* options, int num_of_options,  Border border = NONE)
:List( false,w, h, start_coord, bg_color,txt_color,head_line, options, num_of_options, border){
    this->show_list=false;

}

/*
    create checkedOption for each option
*/


/*
    create checkedOption for each option
*/
void ComboBox::setShowList(){
    if(this->show_list){
        this->show_list=false;
        this->_draw();
    }
    else{
        this->show_list=true;
        this->_draw();
    }
}

void ComboBox::selectOption(){

}

/*
    create checkedOption for each option
*/


/*
    create checkedOption for each option
*/
void ComboBox::_draw(){
    List::_draw();
    this->show_button->_draw();
    this->selected_option_text->_draw();
    if(this->show_list){
        ///draw options
    }
    }
/*
    create checkedOption for each option
*/
void ComboBox::setOptions(string* options, int num_of_options){
    
    
}
ComboBox::~ComboBox(){

}
