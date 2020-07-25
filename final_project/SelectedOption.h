#pragma once

#include <string>
#include <windows.h>
#include <string>
#include <iostream>
#include "Option.h"

using namespace std;

class SelectedOption: public Option {
    public:
        SelectedOption(string label, DWORD txt_color, DWORD bg_color, HANDLE outHandle);
        virtual void setIsSelected();
        ~SelectedOption();
};