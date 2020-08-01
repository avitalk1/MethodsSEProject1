#include "Label.h"

Label::Label(COORD start_coord, DWORD bg_color, DWORD txt_color, std::string txt, Border border): 
    Component(1, 1, start_coord, bg_color, txt_color, border)
{
    this->setText(txt);
   
}
void Label::setText(std::string txt)
{
    this->text = txt;
}

std::string Label::getText()
{
    return this->text;
}

void Label::eventListener(char T) {}
bool amILabel(){
    return true;
}
void Label::_draw()
{
     WORD prevAttribute;
    _CONSOLE_SCREEN_BUFFER_INFO bi;
    GetConsoleScreenBufferInfo(outHandle, &bi);
    prevAttribute = bi.wAttributes;
    //auto outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(outHandle, this->start_coordinate);
    SetConsoleTextAttribute(outHandle, this->text_color|this->background_color);
    std::cout << text;
    SetConsoleTextAttribute(outHandle, prevAttribute);      //set colors back to prev
    CONSOLE_CURSOR_INFO info = {1, 0};
    SetConsoleCursorInfo(outHandle, &info);
}