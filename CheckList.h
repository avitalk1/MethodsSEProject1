
#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include "List.h"
#include "CheckedOption.h"
using namespace std;

class CheckList : public List {
    
    public:
        CheckList(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color, string head_line, string* options, int num_of_options,  Border border = NONE);
        virtual void _draw();
        virtual void selectOption();
        virtual void setOptions(string* options_labels, int num_of_options);
        ~CheckList();
};