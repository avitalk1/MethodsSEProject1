#include "Panel.h"
bool Panel::mainPanelSignal(){
    this->amImainPanel=true;
}
COORD Panel::currentLocation(){
    if(this->curr_component!=NULL){
        return this->curr_component->currentLocation();
    }
    else{
        return this->getCoordinate();
    }
}
Panel::Panel(HandleIO* IO,COORD start_coord, DWORD bg_color, DWORD txt_color, Border border, int height, int width) : Component(width, height, start_coord, bg_color, txt_color, border)
{
    this->io=IO;
    this->parent_panel=NULL;
    this->curr_component = NULL;
    this->num_of_components = 0;
    this->curr_component_index = -1;
    this->amImainPanel=false;
}
void Panel::addComponent(Component *component)
{
    // if (typeid(component).name() == typeid(MessageBoxComp).name())
    //     {
    //            (static_cast<MessageBoxComp *>(component))->setPanel(this);
    //     }
    if (component->amIPanel())
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
        if (this->amImainPanel)
        {
            curr_component = components[0];
            curr_component_index = 0;
            CONSOLE_CURSOR_INFO info = {1, 1};  
            SetConsoleCursorInfo(outHandle, &info);  
            SetConsoleCursorPosition(outHandle,this->curr_component->currentLocation());
        }
        else
        {
            this->curr_component_index=0;
            this->curr_component=components[0];
            //io->setCurrPanel(parent_panel);
            parent_panel->nextComponent();
        }
    }
    else{
        curr_component = components[curr_component_index];
        // if(curr_component->amILabel()){
        //     nextComponent();
        // }
        CONSOLE_CURSOR_INFO info = {1, 1};  
        SetConsoleCursorInfo(outHandle, &info);  
        SetConsoleCursorPosition(outHandle,this->curr_component->currentLocation());
    }
        
    
}
void Panel::eventListener(char T)
{
   
        if(T==0x09) //tab (VK_TAB) (used to navigate between controllers)
        {
            if(this->components[curr_component_index]->amIPanel()){
                this->components[curr_component_index]->eventListener(0x09);
            }
            else{
                nextComponent();
            }
                    
        }
 
        else{
           if(this->curr_component_index!=this->num_of_components) 
                this->components[this->curr_component_index]->eventListener(T);
            else{

            }
        }
    
}
bool Panel::amIPanel(){return true;}
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
        SetConsoleCursorPosition(outHandle, this->curr_component->currentLocation());
    }
}
void Panel::setParentPanel(Panel *parent)
{
    this->parent_panel = parent;
}

int Panel::getHeight(){
    int h=this->height;
    int temp=0;
    int max=h;
    for(int i=0;i<this->num_of_components;i++)
    {
        temp=int(components[i]->getCoordinate().Y-this->getCoordinate().Y)+this->components[i]->getHeight();
        if (temp<0)
        {
            temp=-temp;
        }
        if(temp>max)
        {
            max = h+ temp;
        }
    }
    
    return max+2;
}
int Panel::getWidth(){
    int w=this->width;
    int max=w;
    int temp =0;
    for(int i=0;i<this->num_of_components;i++){
        temp=components[i]->getWidth()+int(components[i]->getCoordinate().X-this->getCoordinate().X);
        if(temp>max){
            max= w+temp;
        }
    }
    return max+2;
}

// int Panel::getHeight(){
//     int h=this->height;
    
//     for(int i=0;i<this->num_of_components;i++){
//         h=h+components[i]->getHeight();
//     }
//     return h;
// }
// int Panel::getWidth(){
//     int w=this->width;
//     int max=w;
//     for(int i=0;i<this->num_of_components;i++){
//         if(components[i]->getWidth()>max){
//             max= w+components[i]->getWidth();
//         }
//     }
//     return max;
// }
Panel::~Panel() {
    for(int i = 0;i<this->num_of_components;i++){
        delete(components[i]);
    }
}
