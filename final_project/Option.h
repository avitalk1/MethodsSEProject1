#pragma once

#include <string>
#include <windows.h>
#include <string>
#include <iostream>
#include "Label.h"

using namespace std;

class Option {
    Label label;
    COORD coordinate;
    DWORD background_color;
    DWORD text_color;
    bool is_selected;
    HANDLE outHandle;


    public:
        Option(string label, DWORD txt_color, DWORD bg_color);

        void setLabel(string label);
        Label getLabel();

        virtual void setIsSelected() = 0;
        bool getIsSelected();

        void setCoordinate(COORD coord);
        COORD getCoordinate();

        virtual void drawOption();

        void setBackgroundColor(DWORD color);
        void setTextColor(DWORD color);
        DWORD getBackgroundColor();
        DWORD getTextColor();
        virtual ~Option() = 0;
};