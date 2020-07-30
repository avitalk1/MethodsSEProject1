
#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include "List.h"
#include "Button.h"
#include "SelectedOption.h"
#include "ListenerShowList.h"
using namespace std;

class ComboBox : public List {
    Button* show_button;
    Label* selected_option_text;
    bool on_list;
    bool show_list;
    public:
        ComboBox(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color, string head_line, string* options, int num_of_options,  Border border = NONE);
        // virtual void setCurrOption(int option);
        void setShowList();
        virtual void selectOption();
        virtual void setOptions(string* options_labels, int num_of_options);
        virtual void moveToNextOption(ArrowKey key);
        // void undraw();
        virtual void eventListener(char T);
        virtual COORD currentLocation();
        virtual void _draw();
        ~ComboBox();
};