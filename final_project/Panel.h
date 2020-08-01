#pragma once
#include <string> 
#include <windows.h>
#include <iostream>
#include <typeinfo>
#include <vector>
#include "Component.h"
//#include "Label.h"

class HandleIO;
// class MessageBoxComp;

class Panel : public Component {
    
    Panel* parent_panel;
    int num_of_components;
	vector<Component*> components;
    //vector<Label*> labels;
    int curr_component_index;
    HandleIO* io;
    bool amImainPanel;
public:
    
    virtual bool amIPanel();
    virtual bool mainPanelSignal();
    Component* curr_component;
    Panel(HandleIO* IO,COORD start_coord, DWORD bg_color, DWORD txt_color, Border border = NONE, int height = 0, int width =0);
    void addComponent(Component* component);
    void nextComponent();
    virtual void eventListener(char T);
    virtual void _draw();
    void setParentPanel(Panel* parent);
    virtual int getHeight();
    virtual int getWidth();
    virtual COORD currentLocation();
    ~Panel();
};

#include "HandleIO.h"
// #include "MessageBoxComp.cpp"
