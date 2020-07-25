
#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include "List.h"



using namespace std;

class CheckList : public List {
    
    public:
        CheckList(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color,HANDLE outHandle, string head_line, string* options, int num_of_options,  Border border = NONE);
        virtual void setCurrOption(int option);
        virtual void selectOption();
        ~CheckList();
};