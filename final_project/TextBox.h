#pragma once

#include <string>
#include <windows.h>
#include <iostream>
#include "Component.h"

using namespace std;

class TextBox: public Component {
   
    int left_limit = 0, right_limit = 0, top_limit = 0, bottom_limit = 0;
    string buffer;
    string temp_str;
    _CONSOLE_SCREEN_BUFFER_INFO bi;

public:
    TextBox(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color, Border border = NONE);
    virtual void _draw();
    bool setCursor(int x, int y);
    int getLeftLimit();
    int getRightLimit();
    int getTopLimit();
    int getBottomLimit();
    virtual void eventListener(char T);
    int getAbsolutePosition();
    virtual COORD currentLocation();
};