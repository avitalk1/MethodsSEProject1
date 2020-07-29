#include <string> 
#include <windows.h>
#include <iostream>
#include "Component.h"
#include "Button.h"
#include "Label.h"

class NumericBox : public Component {
    Label label;
    int min_limit;
    int max_limit;
    Button minus_button;
    Button plus_button;
    int value;
    public:
        NumericBox(COORD start_coord, DWORD bg_color, DWORD txt_color, std::string txt, Border border = NONE);
        int getValue();
        void setValue();
        void setMinValue();
        int getMinValue();
        void setMaxValue();
        int getMaxValue();
        virtual void eventListener(char T);
        virtual void _draw();
};