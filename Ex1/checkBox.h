#pragma once

#include <string>
#include <windows.h>
#include <string>
#include <iostream>


using namespace std;

class checkBox {
    string text;
    COORD coord;
    DWORD colors;
    int check;


public:
    checkBox();

    void setCoord(COORD coord);
    COORD getCoord();
    void draw(HANDLE outHandle);
    void setColors(DWORD fg);
    DWORD getColors();
    void setText(string text);
    string getText();
    void setCheck(HANDLE outHandle);

};