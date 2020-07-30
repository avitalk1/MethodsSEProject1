#pragma once

#include <string>
#include <windows.h>
#include <string>
#include <iostream>
#include "Label.h"

using namespace std;

class Option {
  
    protected:
        COORD coordinate;
        DWORD background_color;
        DWORD text_color;
        HANDLE outHandle;
        bool is_selected;
    public:
        Option(string label, DWORD txt_color, DWORD bg_color, COORD start_coord);
        virtual void setIsSelected() = 0;
        // void setSelected(bool T);
        bool getIsSelected();
        void setCoordinate(COORD coord);
        COORD getCoordinate();
        virtual void drawOption() = 0;
        void setBackgroundColor(DWORD color);
        void setTextColor(DWORD color);
        DWORD getBackgroundColor();
        DWORD getTextColor();
        virtual ~Option() = 0;
};