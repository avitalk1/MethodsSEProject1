#pragma once
#include "Component.h"
#include "Button.h"
#include "ListenerPlus.h"
// #include "Label.h"
using namespace std;

class NumericBox: public Component {
    Label* label;
    int min_limit;
    int max_limit;
    Button* minus_button;
    Button* plus_button;
    COORD plus_btn_coord;
    COORD label_coord;
    int value;
public:
        NumericBox(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color, int val, int min, int max, Border border = NONE);
        int getValue();
        void setValue(int val);
        void setMinValue(int min);
        int getMinValue();
        void setMaxValue(int max);
        int getMaxValue();
        void Increase();
        virtual void eventListener(char T);
        virtual void _draw();
};