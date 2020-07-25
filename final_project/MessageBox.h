#include <string> 
#include <windows.h>
#include <iostream>
#include "Component.h"
#include "Button.h"
#include "Label.h"

class MessageBox : public Component {
    Label label;
    Button ok_button;
    Button cancel_button;
    string clicked;
    public:
        MessageBox(COORD start_coord, DWORD bg_color, DWORD txt_color,HANDLE outHandle, std::string txt, Border border = NONE);
        string getClicked();
        void setClicked(string clicked);
        void setLabel(string button_label);
        Label getLabel();
        virtual void eventListener(char T);
        virtual void _draw();
};