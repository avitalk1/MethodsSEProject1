#include "Label.h"

Label::Label(std::string value, COORD coord)
{
    setValue(value);
    setCoord(coord);
}

void Label::setValue(std::string value)
{
    this->value = value;
}

std::string Label::getValue()
{
    return this->value;
}

void Label::_write(char T) {}

void Label::_draw()
{
    auto outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(outHandle, coord);
    SetConsoleTextAttribute(outHandle, this->colors);
    std::cout << value;

    CONSOLE_CURSOR_INFO info = {1, 0};
    SetConsoleCursorInfo(outHandle, &info);
}