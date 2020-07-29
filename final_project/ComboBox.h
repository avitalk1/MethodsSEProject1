
#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include "List.h"
#include "Button.h"
#include "SelectedOption.h"
using namespace std;

class ComboBox : public List {
    Button show_button;
    Label selected_option_text;
    public:
        ComboBox(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color, string head_line, string* options, int num_of_options,  Border border = NONE);
        virtual void setCurrOption(int option);
        virtual void selectOption();
        virtual void setOptions(string* options, int num_of_options);
        void undraw();
        virtual void _draw();
        ~ComboBox();
};