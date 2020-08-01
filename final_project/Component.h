#pragma once
#include <windows.h>
#include <string>
#include <iostream>


using namespace std;
enum Border { NONE, SINGLE_LINE, DOUBLE_LINE }; 
class Component {
    protected:
        int width;
        int height;
        COORD start_coordinate;
        DWORD background_color;
        DWORD text_color;
        Border border;
        HANDLE outHandle;
    public:
        Component(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color, Border border = NONE);
        virtual bool amIPanel();
        // virtual bool amILabel();
        virtual void drawBorder();
        void setCoordinate(COORD coord);
        COORD getCoordinate();
        virtual COORD currentLocation();
        void setBackgroundColor(DWORD color);
        void setTextColor(DWORD color);
        DWORD getBackgroundColor();
        DWORD getTextColor();
        void setHeight(int h);
        void setWidth(int w);
        virtual int getHeight();
        virtual int getWidth();
        void setBorder(Border b);
        Border getBorder();
        virtual void _draw() = 0;
        //this was _write
        virtual void eventListener(char T) = 0;

};