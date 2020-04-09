#include <string> 
#include <windows.h>
#include <iostream>

class Label{
    std::string value;
    COORD coord;
    DWORD colors;

    public:
        Label(std::string value, COORD coord);
        
        void setValue(std::string value);
        std::string getValue();

        void setColors(DWORD fc , DWORD bc);
        DWORD getColors();

        void setCoord(COORD coord);
        COORD getCoord();

        void draw();

};