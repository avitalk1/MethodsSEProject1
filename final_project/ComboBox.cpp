
#include "ComboBox.h"
ComboBox::ComboBox(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color, string head_line, string *options, int num_of_options, Border border = NONE)
    : List(false, w, h, start_coord, bg_color, txt_color, head_line, options, num_of_options, border)
{
    this->show_list = false;
    this->on_list=false;
    this->setHeight(h + 4 + (num_of_options * 3));
    this->setWidth(this->width + 2);
    ListenerShowList* show_list_listener = new ListenerShowList();
    COORD show_button_coord = {this->start_coordinate.X, this->start_coordinate.Y + 2};
    this->show_button = new Button(show_button_coord, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED, FOREGROUND_GREEN | FOREGROUND_INTENSITY, this, show_list_listener, NONE ,"V");
    COORD label_coord = {show_button_coord.X + 2, show_button_coord.Y};
    this->selected_option_text = new Label(label_coord, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED, FOREGROUND_GREEN | FOREGROUND_INTENSITY, options[0] );
    this->selected_options[0] = 0;
}
void ComboBox::setShowList()
{
    if (this->show_list)
    {
        this->show_list = false;
        this->_draw();
    }
    else
    {
        this->show_list = true;
        this->_draw();
    }
}
void ComboBox::moveToNextOption(ArrowKey key){
    this->options[this->curr_option]->setIsSelected();
    List:moveToNextOption(key);    
    this->options[this->curr_option]->setIsSelected();
}

void ComboBox::selectOption()
{

        *(this->selected_options)=this->curr_option;
        string new_option =static_cast<SelectedOption*> (this->options[*(this->selected_options)])->getOptionValue();
        this->selected_option_text->setText(new_option);
        this->on_list=false;
        this->show_list=false;
        this->_draw();    
}
void ComboBox::_draw()
{
    List::_draw();
    this->show_button->_draw();
    this->selected_option_text->_draw();
    if (this->show_list)
    {
        for (int i = 0; i < this->number_of_options; i++)
        {
            this->options[i]->drawOption();
        }
    }
    CONSOLE_CURSOR_INFO info = {1, 1};
    SetConsoleCursorPosition(outHandle, this->show_button->currentLocation());

}

void ComboBox::setOptions(string *options_labels, int num_of_options)
{
    COORD start_list_coord = {this->label->getCoordinate().X,this->label->getCoordinate().Y+2};
    for( int i = 0; i < this->number_of_options; i++){
        this->options.push_back(new SelectedOption(start_list_coord, options_labels[i], this->getTextColor(), this->getBackgroundColor(),this->getWidth()));
        start_list_coord={start_list_coord.X,start_list_coord.Y+3};
    }
    this->options[0]->setIsSelected();
}

void ComboBox::eventListener(char T){
    if(show_list){
         
        if (T == 0x26)
        {
            this->moveToNextOption(DOWN_KEY);
        }
        if (T == 0x28)
        {
            this->moveToNextOption(UP_KEY);
        }
        if(T==0x25)//left
        {
            //set curser to button coord
            SetConsoleCursorPosition(outHandle, this->show_button->currentLocation());

            this->on_list =false;
        }
        if(T==0x27)//right
        {
            ////set curser to curr option on list coord
            SetConsoleCursorPosition(outHandle, this->options[this->curr_option]->getCoordinate());
            this->on_list=true;
        }
        
    }
    if (T == 0x0D && this->on_list)
        {
            this->selectOption();
        }
    if (T == 0x0D && this->on_list==false)
        {
            this->show_button->pushButton();
        }
        //if space open/close list (push)
    
}
COORD ComboBox::currentLocation(){
    return this->show_button->getCoordinate();
}
ComboBox::~ComboBox()
{
    delete(show_button);
    delete(selected_option_text);
}
