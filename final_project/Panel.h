#include <string> 
#include <windows.h>
#include <iostream>
#include <typeinfo>
#include "Component.h"
#include "HandleIO.h"

class Panel : public Component {
    Component** components;
    Panel* prev;
    int num_of_components;
	int curr_component_index;

public:
    Component* curr_component;
    Panel(COORD start_coord, DWORD bg_color, DWORD txt_color, Border border = NONE, int height = 0, int width =0);
    void addComponent(Component* component);
    void nextComponent();
    virtual void eventListener(char T);
    virtual void _draw();
    void setPrev(Panel* p);
    ~Panel();
};