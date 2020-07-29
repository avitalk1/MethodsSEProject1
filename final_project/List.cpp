#include "List.h"
// List::List(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color,HANDLE outHandle, string head_line, string* options, int num_of_options,  Border border = NONE):
//     Component(w, h, start_coord, bg_color, txt_color, outHandle, border){
//         this->setLabel(head_line)
// }
// virtual COORD List::currentLocation();
// virtual void List::_draw();
// virtual void List::eventListener(char T);

void List::setLabel(string head_line){
    this->label = new Label(this->start_coordinate, this->background_color, this->text_color, this->outHandle, head_line, NONE);
}
Label* List::getLabel(){
    return this->label;
}
int List::getNumberOfOptions(){
    return this->number_of_options;
}
Option* List::getOptions(){
    return this->options;
}

int List::getCurrOption(){
    return this->curr_option;
}
int* List::getSelectedOption(){
    return this->selected_options;
}

List::~List(){
    delete(this->label);
}

