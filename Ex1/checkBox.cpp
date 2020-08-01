#include "checkBox.h"

checkBox::checkBox() {
    this->check = 0;
}

void checkBox::setCoord(COORD coord) { this->coord = coord; }
COORD checkBox::getCoord() { return this->coord; }
void checkBox::setColors(DWORD fg) { this->colors = fg; }
DWORD checkBox::getColors() { return this->colors; }
void checkBox::setText(string text) { this->text = text; }
string checkBox::getText() { return this->text; }
void checkBox::setCheck(HANDLE outHandle) {
    if (check) { check = 0; }
    else { check = 1; }
    draw(outHandle);
    SetConsoleCursorPosition(outHandle, this->coord);
}
void checkBox::draw(HANDLE outHandle) {
    SetConsoleCursorPosition(outHandle, this->coord);         //set console cursor coordinates
    SetConsoleTextAttribute(outHandle, FOREGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);    //set console checkbox check color gray
    if (this->check) {
        SetConsoleTextAttribute(outHandle, (FOREGROUND_GREEN | FOREGROUND_INTENSITY, BACKGROUND_GREEN));    //s
        cout << "V";
    }
    else {
        cout << " ";
    }
    SetConsoleTextAttribute(outHandle, FOREGROUND_GREEN);    //set space between checkbox and text label color black
    cout << "  ";
    SetConsoleTextAttribute(outHandle, this->colors);             //set console checkbox colors
    cout << text;
}
