#include "CheckList.h"
CheckList::CheckList(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color, string head_line, string* options, int num_of_options,  Border border = NONE):
List( true,w, h, start_coord, bg_color,txt_color,head_line, options, num_of_options, border){}{
    this->curr_option = 0;
}

void CheckList::_draw(){
    List:_draw();
    for(int i = 0; i < this->number_of_options; i++){
        this->options[i]->drawOption();
    }
}
void CheckList::selectOption(){
    this->options[this->curr_option]->setIsSelected();
    if(this->selected_options[this->curr_option] == 0){
        this->selected_options[this->curr_option] = 1;
    }else{
        this->selected_options[this->curr_option] = 0;
    }
}
void CheckList::setOptions(string* options_labels, int num_of_options){
    COORD start_list_coord = {this->label->getCoordinate().X,this->label->getCoordinate().Y+2};
    for(int i = 0; i < num_of_options; i++){
        this->options.push_back(new CheckedOption(options_labels[i], this->getTextColor(), this->getBackgroundColor(), start_list_coord));
        start_list_coord={start_list_coord.X,start_list_coord.Y+2};
    }
}