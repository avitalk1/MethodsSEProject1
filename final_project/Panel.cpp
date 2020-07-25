#include "Panel.h"
Panel::Panel(COORD start_coord, DWORD bg_color, DWORD txt_color,HANDLE outHandle, Border border, int height, int width ):
    Component(width, height, start_coord, bg_color, txt_color, outHandle, border)
{
    this->components = NULL;
    this->curr_component = NULL;
    this->num_of_components = 0;
    this->curr_component_index = -1;
}
void Panel::addComponent(Component* component){
      if (components == NULL) {
        components = new Component * ();
        if (components == NULL) {
            cerr << "alloc";
            exit(1);
        }
        this->curr_component_index = 0;
        this->num_of_components = 1;
        components[0] = component;
        curr_component = components[0];
    }
    else {
        num_of_components++;

        Component** temp = new Component * [num_of_components]();
        if (temp == NULL) {
            cerr << "alloc";
            exit(1);
        }

        int i;
        for (i = 0; i < num_of_components - 1; i++) {
            temp[i] = components[i];
        }
        temp[i] = component;

        delete[] components;
        components = temp;

    }
}
void Panel::eventListener(char T){
    
}
void Panel::_draw(){
     if (compList != NULL) {
        for (int i = 0; i < comp_counter; i++) {
            compList[i]->_draw();
            SetConsoleTextAttribute(outHandle, prevAttribute);      //set colors back to prev
        }
        CONSOLE_CURSOR_INFO info = { 1,1 };
        SetConsoleCursorPosition(outHandle, this->currComp->getCoord());
    }
}
void Panel::nextComponent(){
    curr_component_index++;
    if (curr_component_index == num_of_components) {
        curr_component = components[0];
        curr_component_index = 0;
    }
    else curr_component = components[curr_component_index];
}
Panel::~Panel();
