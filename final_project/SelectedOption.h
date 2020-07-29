#pragma once

#include <string>
#include <windows.h>
#include <string>
#include <iostream>
#include "Option.h"
#include "Button.h"
using namespace std;

class SelectedOption: public Option {
    Button button;
    public:
        SelectedOption(COORD start_coord, string label, DWORD txt_color, DWORD bg_color);
        virtual void setIsSelected();
        ~SelectedOption();
};