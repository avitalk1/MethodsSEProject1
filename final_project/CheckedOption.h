#pragma once

#include <string>
#include <windows.h>
#include <string>
#include <iostream>
#include "Option.h"
#include "Button.h"

using namespace std;

class CheckedOption: public Option {
    Button* button;
    Label* label;
    public:
        CheckedOption(string label, DWORD txt_color, DWORD bg_color,COORD coord);
        virtual void drawOption();
        virtual void setIsSelected();
        ~CheckedOption();
};