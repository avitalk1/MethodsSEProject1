#include "SelectedOption.h"

SelectedOption::SelectedOption(COORD start_coord, string label, DWORD txt_color, DWORD bg_color, int w) : Option(label, txt_color, bg_color, start_coord)
{
    this->button = new Button(start_coord, txt_color, bg_color, NULL, NULL, SINGLE_LINE, label, 1, w);
}

void SelectedOption::setIsSelected()
{
    if(this->is_selected){
        this->is_selected = false;
        this->button->setBackgroundColor(this->getBackgroundColor());
    }else{
        this->is_selected = true;
        this->button->setBackgroundColor(this->getBackgroundColor() | COMMON_LVB_REVERSE_VIDEO);
    }
    this->drawOption();
}
void SelectedOption::drawOption()
{
    this->button->_draw();
}
SelectedOption::~SelectedOption()
{
    delete(button);
}
