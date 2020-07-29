#include "List.h"
List::List(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color, string head_line, string* options, int num_of_options,  Border border = NONE):
    Component(w, h, start_coord, bg_color, txt_color, border){
        this->setLabel(head_line);
}
void List::_draw(){

}
void List::eventListener(char T){
    if (T == 0x0D)
    {
        this->selectOption();
    }
    if (T == 0x26)
    {
        this->moveToNextOption(DOWN_KEY);
    }
    if (T == 0x28)
    {
        this->moveToNextOption(UP_KEY);
    }
}
void List::moveToNextOption(ArrowKey key){
    int move;
    if(key == UP_KEY){
        move = 1;
    }else{
        move = -1;
    }
    this->curr_option += move;

    if(this->curr_option < 0) this->curr_option = this->number_of_options -1;
    if(this->curr_option == this->number_of_options) this->curr_option = 0;

    SetConsoleCursorPosition(outHandle, options[this->curr_option]->getCoordinate()); //set the cursor location

}
void List::setLabel(string head_line){
    this->label = new Label(this->start_coordinate, this->background_color, this->text_color, head_line, NONE);
}
Label* List::getLabel(){
    return this->label;
}
int List::getNumberOfOptions(){
    return this->number_of_options;
}
vector<Option*> List::getOptions(){
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

