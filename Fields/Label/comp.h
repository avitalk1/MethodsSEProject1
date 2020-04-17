#pragma once
#include <string>
#include <windows.h>
#include <string>
#include <iostream>


using namespace std;

class comp {
protected:
    HANDLE outHandle;
    COORD coord;
    DWORD colors;

public:
    comp();

    void setCoord(COORD coord);
    COORD getCoord();
    virtual COORD CurrLocation();
    virtual void setColors(DWORD fg, DWORD bg);
    DWORD getColors();
    virtual void _draw() = 0;
    virtual void _write(char T) = 0;



};