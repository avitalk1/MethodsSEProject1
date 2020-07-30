
#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include "Component.h"
#include "Label.h"
#include "Option.h"
#include <vector>
enum ArrowKey { UP_KEY, DOWN_KEY }; 

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
    
    List(bool is_multi,int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color, string head_line, string* options, int num_of_options,  Border border = NONE);
    virtual COORD currentLocation();
    virtual void _draw();
    virtual void eventListener(char T);
    
    void setLabel(string head_line);
    Label* getLabel();

    virtual void setOptions(string* options, int num_of_options) = 0;
    int getNumberOfOptions();
    vector<Option*> getOptions();

    virtual void moveToNextOption(ArrowKey key);
    virtual void selectOption() = 0;

    int getCurrOption();
    int* getSelectedOption();
    virtual ~List() = 0;
};