#include "RadioList.h"

    RadioList::RadioList(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color, string head_line, string* options, int num_of_options,  Border border)
    :List( false,w, h, start_coord, bg_color,txt_color,head_line, options, num_of_options, border){}
    void RadioList::_draw(){
        List:_draw();
        for(int i=0;i<this->number_of_options;i++){
            this->options[i]->drawOption();
        }
    }
    void RadioList::setOptions(string* options, int num_of_options){
        COORD startList = {this->label->getCoordinate().X,this->label->getCoordinate().Y+2};
        for(int i=0;i<this->number_of_options;i++){
            this->options.push_back(new CheckedOption(options[i],this->text_color,this->background_color,startList));
            startList={startList.X,startList.Y+2};
        }
        this->options[0]->setIsSelected();
        *(this->selected_options)=0;

    }
    void RadioList::selectOption() {
        if(this->curr_option!=*(this->selected_options)){
            options[*(this->selected_options)]->setIsSelected();
            options[this->curr_option]->setIsSelected();
            *(this->selected_options)=this->curr_option;
        }
    }
    RadioList::~RadioList() {

    }