#pragma once
#include <string>
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
        Component(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color,HANDLE outHandle, Border border = NONE);
        void setCoordinate(COORD coord);
        COORD getCoordinate();
        virtual COORD currentLocation();
        void setBackgroundColor(DWORD color);
        void setTextColor(DWORD color);
        DWORD getBackgroundColor();
        DWORD getTextColor();
        void setHeight(int h);
        void setWidth(int w);
        int getHeight();
        int getWidth();
        void setBorder(Border b);
        Border getBorder();
        virtual void _draw() = 0;
        //this was _write
        virtual void eventListener(char T) = 0;

};