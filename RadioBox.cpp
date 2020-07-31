#include "RadioBox.h"

    RadioBox::RadioBox(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color, string head_line, string* options, int num_of_options,  Border border)
    :List( false,w, h, start_coord, bg_color,txt_color,head_line, options, num_of_options, border){
        this->setOptions(options, num_of_options);
        this->curr_option = 0;
    }
    void RadioBox::_draw(){
        List:_draw();
        for(int i=0;i<this->number_of_options;i++){
            this->options[i]->drawOption();
        }
    }
    void RadioBox::setOptions(string* options, int num_of_options){
        COORD start_list_coord = {this->label->getCoordinate().X,this->label->getCoordinate().Y+2};
        for(int i=0;i<this->number_of_options;i++){
            this->options.push_back(new CheckedOption(options[i],this->text_color,this->background_color,start_list_coord));
            start_list_coord={start_list_coord.X,start_list_coord.Y+2};
        }
        this->options[0]->setIsSelected();
        *(this->selected_options)=0;

    }
    void RadioBox::selectOption() {
        if(this->curr_option!=*(this->selected_options)){
            options[*(this->selected_options)]->setIsSelected();
            options[this->curr_option]->setIsSelected();
            *(this->selected_options)=this->curr_option;
        }
    }
    RadioBox::~RadioBox() {

    }