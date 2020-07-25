
#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include "List.h"
#include "Button.h"
using namespace std;

class ComboBox : public List {
    Button show_button;
    Label selected_option_text;
    public:
        ComboBox(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color,HANDLE outHandle, string head_line, string* options, int num_of_options,  Border border = NONE);
        virtual void setCurrOption(int option);
        virtual void selectOption();
        void undraw();
        virtual void _draw();
        ~ComboBox();
};