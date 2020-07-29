
#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include "Component.h"
#include "Label.h"
#include "Option.h"
#include <vector>

using namespace std;

class List : public Component {
    protected:
    Label* label;
    int number_of_options;
    int curr_option;
    bool is_multi;
    int* selected_options;
    vector<Option*> options;
public:
    
    List(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color, string head_line, string* options, int num_of_options,  Border border = NONE);
    virtual COORD currentLocation();
    virtual void _draw();
    virtual void eventListener(char T);
    
    void setLabel(string head_line);
    Label* getLabel();

    virtual void setOptions(string* options, int num_of_options) = 0;
    int getNumberOfOptions();
    Option* getOptions();

    virtual void setCurrOption(int option) = 0;
    virtual void selectOption() = 0;

    int getCurrOption();
    int* getSelectedOption();
    virtual ~List() = 0;
};