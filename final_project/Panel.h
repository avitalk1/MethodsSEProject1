#pragma once
#include <string> 
#include <windows.h>
#include <iostream>
#include <typeinfo>
#include <vector>
#include "Component.h"


class Panel : public Component {
    vector<Component*> components;
    Panel* parent_panel;
    int num_of_components;
	int curr_component_index;

public:
    Component* curr_component;
    Panel(COORD start_coord, DWORD bg_color, DWORD txt_color, Border border = NONE, int height = 0, int width =0);
    void addComponent(Component* component);
    void nextComponent();
    virtual void eventListener(char T);
    virtual void _draw();
    void setParentPanel(Panel* parent);
    virtual int getHeight();
    virtual int getWidth();
    ~Panel();
};

#include "HandleIO.h"