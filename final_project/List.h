
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
    int* getInput();
    List(bool is_multi,int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color, string head_line, string* options, int num_of_options,  Border border = NONE);
    virtual void _draw();
    virtual void eventListener(char T);
    virtual void moveToNextOption(ArrowKey key);
    void setLabel(string head_line);
    Label* getLabel();
    int getNumberOfOptions();
    vector<Option*> getOptions();
    int getCurrOption();
    int* getSelectedOption();
    virtual COORD currentLocation();
    virtual void setOptions(string* options, int num_of_options) = 0;
    virtual void selectOption() = 0;
    virtual ~List() = 0;
};