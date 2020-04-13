#include <string> 
#include <windows.h>
#include <iostream>
#include "comp.h"

class Label : public comp {
    std::string value;
    //COORD coord;
    //DWORD colors;

public:
    Label(std::string value, COORD coord);

    void setValue(std::string value);
    std::string getValue();
    virtual void _write(char T);
    virtual void _draw();

};