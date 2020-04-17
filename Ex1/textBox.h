#pragma once

#include <string>
#include <windows.h>
#include <iostream>
#include "comp.h"

using namespace std;

class textBox: public comp {
    int width = 0;
    int length = 0;
    int leftLim = 0, rightLim = 0, upLim = 0, downLim = 0;
    // bool flag = false;

// protected:
    string buffer;
    string tempStr;
    _CONSOLE_SCREEN_BUFFER_INFO bi;

public:
    textBox(COORD coord, int width, int length);
    virtual void _draw();
    bool SetCursor(int x, int y);
    int getLeftLim();
    int getRightLim();
    int getUpLim();
    int getDownLim();
    virtual void _write(char T);
    int getAbsPos();
    virtual COORD CurrLocation();
};