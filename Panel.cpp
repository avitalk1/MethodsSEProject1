#include "Panel.h"
Panel::Panel(HandleIO* IO,COORD start_coord, DWORD bg_color, DWORD txt_color, Border border, int height, int width) : Component(width, height, start_coord, bg_color, txt_color, border)
{
    this->io=IO;
    this->curr_component = NULL;
    this->num_of_components = 0;
    this->curr_component_index = -1;
}
void Panel::addComponent(Component *component)
{
    // if (typeid(component).name() == typeid(MessageBoxComp).name())
    //     {
    //            (static_cast<MessageBoxComp *>(component))->setPanel(this);
    //     }
    if (typeid(component).name() == typeid(Panel).name())
    {
        (static_cast<Panel *>(component))->parent_panel = this;
    }
    this->components.push_back(component);
    this->num_of_components++;

    //if this is the first component added init curr_component to it
    if (this->num_of_components == 1)
    {
        this->curr_component = this->components[0];
        this->curr_component_index = 0;
    }
}
void Panel::nextComponent()
{
    curr_component_index++;
    if (curr_component_index == num_of_components)
    {
        if (parent_panel == this)
        {
            curr_component = components[0];
            curr_component_index = 0;
        }
        else
        {
            
            io->setCurrPanel(parent_panel);
            parent_panel->nextComponent();
        }
    }
    else
        curr_component = components[curr_component_index];
}
void Panel::eventListener(char T)
{
    switch (T)
    {
        case 0x09: //tab (VK_TAB) (used to navigate between controllers)
        {
            nextComponent();
            break;
        }
 
        case 0x0D: //enter (VK_RETURN) (used in checkbox controller)
        {
            if (typeid(curr_component).name() == typeid(Panel).name())
            {
                
               
                    this->io->setCurrPanel(static_cast<Panel *>(curr_component));
                
                
            }
            break;
        }
    }
}
void Panel::_draw()
{
    //draw panel
    this->drawBorder();
    if (components.size() != 0)
    {
        
        for (int i = 0; i < num_of_components; i++)
        {
            components[i]->_draw();
            SetConsoleTextAttribute(outHandle, this->io->prevAttribute); //set colors back to prev
        }
        CONSOLE_CURSOR_INFO info = {1, 1};
        SetConsoleCursorPosition(outHandle, this->curr_component->getCoordinate());
    }
}
void Panel::setParentPanel(Panel *parent)
{
    this->parent_panel = parent;
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
Panel::~Panel() {
    for(int i = 0;i<this->num_of_components;i++){
        delete(components[i]);
    }
}