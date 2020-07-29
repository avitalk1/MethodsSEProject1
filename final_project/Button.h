#include <string> 
#include <windows.h>
#include <iostream>
#include "Component.h"
#include "Label.h"
#include "Listener.h"
class Button : public Component {
    Label label;
    Listener* listener;
    Component* component;
public:
    Button(COORD start_coord, DWORD bg_color, DWORD txt_color, std::string txt, Listener* listener, Border border = NONE);
    void setLabel(string button_label);
    Label getLabel();
    void setListener(Listener* listener);
    Listener* getListener();
    virtual void eventListener(char T);
    void _draw();
    ~Button();
};