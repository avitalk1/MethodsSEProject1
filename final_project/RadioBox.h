
#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include "List.h"
#include "CheckedOption.h"

using namespace std;

class RadioBox : public List {
    public:
        RadioBox(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color, string head_line, string* options, int num_of_options,  Border border = NONE);
        virtual void setOptions(string* options_labels, int num_of_options);
        virtual void setCurrOption(int option);
        virtual void selectOption();
        ~RadioBox();
};