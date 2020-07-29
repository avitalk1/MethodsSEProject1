#include "RadioBox.h"
RadioBox::RadioBox(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color, string head_line, string* options, int num_of_options,  Border border = NONE){

}
void RadioBox::setCurrOption(int option){
    this->curr_option = option;
}
void RadioBox::selectOption(){

}

void RadioBox::setOptions(string* options_labels, int num_of_options){
     for(int i = 0; i < num_of_options; i++){
        CheckedOption* new_option = new CheckedOption(options_labels[i], this->getTextColor(), this->getBackgroundColor());
        this->options.push_back(new_option);
    }
}
RadioBox::~RadioBox(){

}
