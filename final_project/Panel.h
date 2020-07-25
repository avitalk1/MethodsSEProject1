#include <string> 
#include <windows.h>
#include <iostream>
#include "Component.h"

class Panel : public Component {
    Component** components;
    Component* curr_component;
    int num_of_components;
	int curr_component;
public:
    Panel(COORD start_coord, DWORD bg_color, DWORD txt_color,HANDLE outHandle, Border border = NONE);
    void addComponent(Component* component);
    virtual void eventListener(char T);
    virtual void _draw();
    ~Panel();
};