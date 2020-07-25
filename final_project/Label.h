#include <string> 
#include <windows.h>
#include <iostream>
#include "Component.h"

class Label : public Component {
    std::string text;
public:
    Label(COORD start_coord, DWORD bg_color, DWORD txt_color,HANDLE outHandle, std::string txt, Border border = NONE);
    void setText(std::string txt);
    std::string getText();
    virtual void eventListener(char T);
    virtual void _draw();
};