#include "List.h"
List::List(bool is_multi, int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color, string head_line, string *options, int num_of_options, Border border) : Component(w, h, start_coord, bg_color, txt_color, border)
{
    this->setLabel(head_line);
    this->number_of_options = num_of_options;
    int max = w;
    for (int i = 0; i < num_of_options; i++)
    {
        if (options[i].length() > max)
        {
            max += options[i].length();
        }
    }
    this->setWidth(max);
    this->setHeight(h + (2 * number_of_options));
    // this->setOptions(options, num_of_options);
    this->is_multi = is_multi;
    if (is_multi)
    {
        selected_options = new int[number_of_options]();
        for(int i = 0 ; i < this->number_of_options; i++){
            this->selected_options[i] = 0;
        }
    }
    else
    {
        selected_options = new int();
        this->selected_options[0] = 0;
    }
}
void List::_draw()
{
    this->drawBorder();
    this->label->_draw();
}
void List::eventListener(char T)
{
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
void List::moveToNextOption(ArrowKey key)
{
    int move;
    if (key == UP_KEY)
    {
        move = 1;
    }
    else
    {
        move = -1;
    }
    this->curr_option += move;

    if (this->curr_option < 0)
        this->curr_option = this->number_of_options - 1;
    if (this->curr_option == this->number_of_options)
        this->curr_option = 0;

    SetConsoleCursorPosition(outHandle, options[this->curr_option]->getCoordinate()); //set the cursor location
}
void List::setLabel(string head_line)
{
    this->label = new Label(this->start_coordinate, this->background_color, this->text_color, head_line, NONE);
}
Label *List::getLabel()
{
    return this->label;
}
int List::getNumberOfOptions()
{
    return this->number_of_options;
}
vector<Option *> List::getOptions()
{
    return this->options;
}

int List::getCurrOption()
{
    return this->curr_option;
}
int *List::getSelectedOption()
{
    return this->selected_options;
}
COORD List::currentLocation(){
    return this->options[this->curr_option]->getCoordinate();
}
List::~List()
{
    delete (this->label);
    for (int i = 0; i < this->number_of_options; i++)
    {
        delete (this->options[i]);
    }
    delete (selected_options);
}
