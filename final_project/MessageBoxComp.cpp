#include "MessageBoxComp.h"
void MessageBoxComp::setPanel(Component* p){
    this->panel=p;
}
MessageBoxComp::MessageBoxComp(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color,string txt, Border border):
Component(1, 1, start_coord, bg_color, txt_color, border)
{
    cancel_btn_position.X=start_coord.X;
    cancel_btn_position.Y-start_coord.Y + 1;
    ok_btn_position.X=start_coord.X + txt.length() + 1;
    ok_btn_position.Y=start_coord.Y + 1;
    this->label = new Label(start_coord, bg_color, txt_color, txt, border);
    ListenerOk* ok_listener = new ListenerOk();
    this->ok_button = new Button(ok_btn_position, bg_color, txt_color,this,ok_listener , SINGLE_LINE, "OK");
    ListenerCancel* cancel_listener = new ListenerCancel();
    this->cancel_button = new Button(cancel_btn_position, bg_color, txt_color,this, cancel_listener, SINGLE_LINE, "CANCEL");
    this->curr_button=this->ok_button;
    this->panel=NULL;
}
void MessageBoxComp::setLabel(string button_label){this->label->setText(button_label);}
Label* MessageBoxComp::getLabel(){return this->label;}
void MessageBoxComp::eventListener(char T){
    COORD cursor_location;
    _CONSOLE_SCREEN_BUFFER_INFO bi;
    switch (T)
    {
    case 0x25: //left arrow (VK_LEFT)
    {
        GetConsoleScreenBufferInfo(outHandle, &bi);                         //gets the current location of the cursor
        cursor_location = bi.dwCursorPosition;
        if ((cursor_location.X == ok_btn_position.X)&&(cursor_location.Y == ok_btn_position.Y)) // check if the cursor is on the ok button
        {
            SetConsoleCursorPosition(outHandle, cancel_btn_position);              //set new cursor position to the cancel button
            this->curr_button=this->cancel_button;
        }
        else{
            SetConsoleCursorPosition(outHandle, ok_btn_position);              //set new cursor position to the ok button
            this->curr_button=this->ok_button;
        }
        break;
    }
    case 0x27: //right arrow (VK_RIGHT)
    {
        GetConsoleScreenBufferInfo(outHandle, &bi);                         //gets the current location of the cursor
        cursor_location = bi.dwCursorPosition;
        if ((cursor_location.X == ok_btn_position.X)&&(cursor_location.Y == ok_btn_position.Y)) // check if the cursor is on the ok button
        {
            SetConsoleCursorPosition(outHandle, cancel_btn_position);              //set new cursor position to the cancel button
            this->curr_button=this->cancel_button;
        }
        else{
            SetConsoleCursorPosition(outHandle, ok_btn_position);              //set new cursor position to the ok button
            this->curr_button=this->ok_button;
        }
        break;
    }
    case 0x20: //SPACEBAR key
    {
        curr_button->pushButton();
    }
    default:
    {
        break;
    }
    }
}
void MessageBoxComp::_draw(){
    GetConsoleScreenBufferInfo(outHandle, &bi);        //gets the current location of the cursor
    prevCursorLocation = bi.dwCursorPosition;               //save the prev cursor location  
    CONSOLE_CURSOR_INFO info = {1, 0};                           //set cursor invisible   Lvalue= size (1-100), Rvalue= setVisable(0 or 1)
    SetConsoleCursorInfo(outHandle, &info);                      //hide input cursor
    SetConsoleCursorPosition(outHandle, this->start_coordinate); //set console messageBox coordinates
    DWORD colors = this->text_color | this->background_color;
    SetConsoleTextAttribute(outHandle, colors); //set console messageBox colors
    // saveCurrentScreen();
    drawBorder();
    this->label->_draw();
    this->cancel_button->_draw();
    this->ok_button->_draw();
    SetConsoleCursorPosition(outHandle, this->ok_btn_position);
}
MessageBoxComp::~MessageBoxComp(){
    delete this->label;
    delete this->ok_button;
    delete this->cancel_button;
}
bool MessageBoxComp::clickOk(){
    cls(outHandle); 
    this->panel->_draw();
    SetConsoleCursorPosition(outHandle, this->prevCursorLocation);
    return true;
}
bool MessageBoxComp::clickCancel(){
    cls(outHandle); 
    this->panel->_draw();
    SetConsoleCursorPosition(outHandle, this->prevCursorLocation);
    return false;
}

void MessageBoxComp::cls( HANDLE hConsole )
{
   COORD coordScreen = { 0, 0 };    // home for the cursor 
   DWORD cCharsWritten;
   CONSOLE_SCREEN_BUFFER_INFO csbi; 
   DWORD dwConSize;

// Get the number of character cells in the current buffer. 

   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
   {
      return;
   }

   dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

   // Fill the entire screen with blanks.

   if( !FillConsoleOutputCharacter( hConsole,        // Handle to console screen buffer 
                                    (TCHAR) ' ',     // Character to write to the buffer
                                    dwConSize,       // Number of cells to write 
                                    coordScreen,     // Coordinates of first cell 
                                    &cCharsWritten ))// Receive number of characters written
   {
      return;
   }

   // Get the current text attribute.

   if( !GetConsoleScreenBufferInfo( hConsole, &csbi ))
   {
      return;
   }

   // Set the buffer's attributes accordingly.

   if( !FillConsoleOutputAttribute( hConsole,         // Handle to console screen buffer 
                                    csbi.wAttributes, // Character attributes to use
                                    dwConSize,        // Number of cells to set attribute 
                                    coordScreen,      // Coordinates of first cell 
                                    &cCharsWritten )) // Receive number of characters written
   {
      return;
   }

   // Put the cursor at its home coordinates.

   SetConsoleCursorPosition( hConsole, coordScreen );
}

// void MessageBoxComp::saveCurrentScreen(){}
// void MessageBoxComp::loadPrevScreen(){}
