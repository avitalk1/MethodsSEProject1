#include "Label.h"

Label::Label(COORD start_coord, DWORD bg_color, DWORD txt_color, std::string txt, Border border = NONE): 
    Component(1, 1, start_coord, bg_color, txt_color, border)
{
    this->setText(txt);
   
}

void Label::setText(std::string value)
{
    this->text = value;
}

std::string Label::getText()
{
    return this->text;
}

void Label::eventListener(char T) {}

void Label::_draw()
{
    auto outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(outHandle, this->start_coordinate);
    SetConsoleTextAttribute(outHandle, this->text_color|this->background_color);
    std::cout << text;

    CONSOLE_CURSOR_INFO info = {1, 0};
    SetConsoleCursorInfo(outHandle, &info);
}