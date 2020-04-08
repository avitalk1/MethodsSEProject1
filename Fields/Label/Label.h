#include <string> 
#include <windows.h>

class Label{
    std::string value;
    COORD coord;

    public:
        Label(std::string value, COORD coord) : value(value), coord(coord) {};

        void setValue(std::string value);
        std::string getValue();

        void setCoord(COORD coord);
        COORD getCoord();
};
