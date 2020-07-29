#include "Panel.h"
Panel::Panel(COORD start_coord, DWORD bg_color, DWORD txt_color,HANDLE outHandle, Border border, int height, int width ):
    Component(width, height, start_coord, bg_color, txt_color, outHandle, border)
{
    this->components = NULL;
    this->curr_component = NULL;
    this->num_of_components = 0;
    this->curr_component_index = -1;
}
int Panel::getHeight(){
    int h=this->height;
    
    for(int i=0;i<this->num_of_components;i++){
        h=h+components[i]->getHeight();
    }
    return h;
}
int Panel::getWidth(){
    int w=this->width;
    int max=w;
    for(int i=0;i<this->num_of_components;i++){
        if(components[i]->getWidth()>max){
            max= w+components[i]->getWidth();
        }
    }
    return max;
}
void Panel::addComponent(Component* component){
      if(typeid(component).name()== typeid(Panel).name()){
                (static_cast<Panel*>(component))->prev=this;
         }
             
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
    switch (T) {
    
   
    case 0x09:    //tab (VK_TAB) (used to navigate between controllers)
    {
        
         nextComponent();
        break;
    }
  
    
    case 0x0D: //enter (VK_RETURN) (used in checkbox controller)
    {

        
            if(typeid(curr_component).name()== typeid(Panel).name()){
                IO->setCurrPanel(static_cast<Panel*>(curr_component));
                }
             
    
        break;
    
    }
}
}

void Panel::setPrev(Panel* p){
    this->prev=p;
}
void Panel::_draw(){
     if (components != NULL) {
        for (int i = 0; i < num_of_components; i++) {
            components[i]->_draw();
            SetConsoleTextAttribute(outHandle, IO->prevAttribute);      //set colors back to prev
        }
        CONSOLE_CURSOR_INFO info = { 1,1 };
        SetConsoleCursorPosition(outHandle, this->curr_component->getCoordinate());
    }
}
void Panel::nextComponent(){
    curr_component_index++;
    if (curr_component_index == num_of_components) {
        if(prev==this){
            curr_component = components[0];
            curr_component_index = 0;
        }
        else{
            IO->setCurrPanel(prev);
            prev->nextComponent();
        }
    }
    else curr_component = components[curr_component_index];
}
Panel::~Panel(){}
