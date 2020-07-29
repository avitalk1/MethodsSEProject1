#include "NumericBox.h"

NumericBox::NumericBox(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color, int val, int min, int max, Border border = NONE) : Component(1, 1, start_coord, bg_color, txt_color, border)
{
    this->min_limit = min;
    this->max_limit - max;
    this->value = val;
    label_coord = start_coordinate;
    start_coordinate.X = start_coordinate.X + 2;
    this->label = new Label(label_coord, bg_color, txt_color, to_string(val), border);
    this->minus_button = new Button(start_coord, bg_color, txt_color,this,listener * , SINGLE_LINE, "-");
    this->plus_btn_coord = start_coordinate;
    plus_btn_coord.X = start_coord.X + to_string(max_limit).length() + 2;
    ListenerPlus* plus_listener = new ListenerPlus();
    this->plus_button = new Button(plus_btn_coord, bg_color, txt_color,this, plus_listener, SINGLE_LINE, "+");
    this->curr_button=this->plus_button;
}
int NumericBox::getValue() { return this->value; }
void NumericBox::setValue(int val) { this->value = val; }
void NumericBox::setMinValue(int min) { this->min_limit = min; }
int NumericBox::getMinValue() { return this->min_limit; }
void NumericBox::setMaxValue(int max) { this->max_limit = max; }
int NumericBox::getMaxValue() { return this->max_limit; }
NumericBox::~NumericBox(){
    delete this->label;
    delete this->minus_button;
    delete this->plus_button;
    delete this->curr_button;
}
void NumericBox::Decrease(){
    if(this->value > this->getMinValue()){
        this->value -= 1;
        this->label->setText(to_string(this->value));
        SetConsoleCursorPosition(outHandle,label_coord);        //set cursor to start label coordinate in order to print the updated label
        for (int i=0; i<to_string(max_limit).length(); ++i) //clear the old label
            cout << " ";
        // SetConsoleCursorPosition(outHandle,label_coord);        //set cursor to start label coordinate in order to print the updated label
        label->_draw();     //draw new label
        // this->plus_btn_coord = start_coordinate;            
        // plus_button->_draw();
        SetConsoleCursorPosition(outHandle, plus_btn_coord);            //set cursor position back to plus button
    }
}
void NumericBox::Increase(){
    if(this->value < this->getMaxValue()){
        this->value += 1;
        this->label->setText(to_string(this->value));
        SetConsoleCursorPosition(outHandle,label_coord);        //set cursor to start label coordinate in order to print the updated label
        for (int i=0; i<to_string(max_limit).length(); ++i) //clear the old label
            cout << " ";
        // SetConsoleCursorPosition(outHandle,label_coord);        //set cursor to start label coordinate in order to print the updated label
        label->_draw();     //draw new label
        // plus_button->_draw();
        SetConsoleCursorPosition(outHandle, start_coordinate);              //set cursor position back to minus button
    }
}
void NumericBox::_draw()
{
    CONSOLE_CURSOR_INFO info = {1, 0};                           //set cursor invisible   Lvalue= size (1-100), Rvalue= setVisable(0 or 1)
    SetConsoleCursorInfo(outHandle, &info);                      //hide input cursor
    SetConsoleCursorPosition(outHandle, this->start_coordinate); //set console textbox coordinates
    DWORD colors = this->text_color | this->background_color;
    SetConsoleTextAttribute(outHandle, colors); //set console textbox colors
    drawBorder();
    minus_button->_draw();
    cout << " ";
    label->_draw();
    cout << " ";
    plus_button->_draw();
    SetConsoleCursorPosition(outHandle, this->start_coordinate); //set console cursor coordinates
    info = {1, 1};                                               //set cursor visible    Lvalue= size (1-100), Rvalue= setVisable(0 or 1)
    SetConsoleCursorInfo(outHandle, &info);                      //show input cursor
}
void NumericBox::eventListener(char T)
{
    COORD cursor_location;
    _CONSOLE_SCREEN_BUFFER_INFO bi;
    switch (T)
    {
    case 0x25: //left arrow (VK_LEFT)
    {
        GetConsoleScreenBufferInfo(outHandle, &bi);                         //gets the current location of the cursor
        cursor_location = bi.dwCursorPosition;
        if ((cursor_location.X == start_coordinate.X)&&(cursor_location.Y == start_coordinate.Y)) // check if the cursor is on the minus button
        {
            SetConsoleCursorPosition(outHandle, plus_btn_coord);              //set new cursor position to the plus button
            this->curr_button=this->plus_button;
        }
        else{
            SetConsoleCursorPosition(outHandle, start_coordinate);              //set new cursor position to the plus button
            this->curr_button=this->minus_button;
        }
        break;
    }
    case 0x27: //right arrow (VK_RIGHT)
    {
        GetConsoleScreenBufferInfo(outHandle, &bi);                         //gets the current location of the cursor
        cursor_location = bi.dwCursorPosition;
        if ((cursor_location.X == start_coordinate.X)&&(cursor_location.Y == start_coordinate.Y)) // check if the cursor is on the minus button
        {
            SetConsoleCursorPosition(outHandle, plus_btn_coord);              //set new cursor position to the plus button
            this->curr_button=this->plus_button;
        }
        else{
            SetConsoleCursorPosition(outHandle, start_coordinate);              //set new cursor position to the plus button
            this->curr_button=this->minus_button;
        }
        break;
    }
    case 0x20: //SPACEBAR key
    {
        curr_button->pushButton();
        // DWORD colors = this->text_color | this->background_color;
        // SetConsoleTextAttribute(outHandle, colors);                 //set console textbox colors
        // GetConsoleScreenBufferInfo(outHandle, &bi);                         //gets the current location of the cursor
        // cursor_location = bi.dwCursorPosition;
        // if ((cursor_location.X == start_coordinate.X)&&(cursor_location.Y == start_coordinate.Y)) // check if the cursor is on the minus button
        // {
        //     curr_button->pushButton();
            // if(this->value < this->getMaxValue()){
            //     this->value += 1;
            //     this->label->setText(to_string(this->value));
            //     SetConsoleCursorPosition(outHandle,label_coord);        //set cursor to start label coordinate in order to print the updated label
            //     for (int i=0; i<to_string(max_limit).length(); ++i) //clear the old label
            //         cout << " ";
            //     // SetConsoleCursorPosition(outHandle,label_coord);        //set cursor to start label coordinate in order to print the updated label
            //     label->_draw();     //draw new label
            //     // plus_button->_draw();
            //     SetConsoleCursorPosition(outHandle, start_coordinate);              //set cursor position back to minus button
            // }
        // }
        // else{                   //else- the cursor is on the plus button
            // if(this->value > this->getMinValue()){
            //     this->value -= 1;
            //     this->label->setText(to_string(this->value));
            //     SetConsoleCursorPosition(outHandle,label_coord);        //set cursor to start label coordinate in order to print the updated label
            //      for (int i=0; i<to_string(max_limit).length(); ++i) //clear the old label
            //         cout << " ";
            //     // SetConsoleCursorPosition(outHandle,label_coord);        //set cursor to start label coordinate in order to print the updated label
            //     label->_draw();     //draw new label
            //     // this->plus_btn_coord = start_coordinate;            
            //     // plus_button->_draw();
            //     SetConsoleCursorPosition(outHandle, plus_btn_coord);            //set cursor position back to plus button
            // }
        // }
    }
    default:
    {
        break;
    }
    }
}