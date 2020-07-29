#include "TextBox.h"

TextBox::TextBox(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color, Border border = NONE):
Component(w, h, start_coord, bg_color, txt_color, border)
{
    this->left_limit = start_coord.X;
    this->right_limit = start_coord.X + w;
    this->top_limit = start_coord.Y;
    this->bottom_limit = start_coord.Y + h;
}

int TextBox::getBottomLimit() { return this->bottom_limit; }
int TextBox::getTopLimit() { return this->top_limit; }
int TextBox::getLeftLimit() { return this->left_limit; }
int TextBox::getRightLimit() { return this->right_limit; }

void TextBox::_draw() {
    COORD temp = this->start_coordinate;
    //auto outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info = { 1, 0 };                 //set cursor invisible   Lvalue= size (1-100), Rvalue= setVisable(0 or 1)
    SetConsoleCursorInfo(outHandle, &info);             //hide input cursor
    SetConsoleCursorPosition(outHandle, this->start_coordinate);         //set console textbox coordinates
    DWORD colors = this->text_color | this->background_color;
    SetConsoleTextAttribute(outHandle, colors);         //set console textbox colors
    drawBorder();
    for (int i = 0; i < this->height; ++i) {
        for (int k = 0; k < this->width; ++k) {
            cout << " ";
        }
        temp.Y += 1;
        SetConsoleCursorPosition(outHandle, temp);      //set console textbox coordinates
    }
    SetConsoleCursorPosition(outHandle,this->start_coordinate);         //set console cursor coordinates
    info = { 1, 1 };                                        //set cursor visible    Lvalue= size (1-100), Rvalue= setVisable(0 or 1)
    SetConsoleCursorInfo(outHandle, &info);              //show input cursor
}

bool TextBox::setCursor(int x, int y) {                              //set cursor location
    COORD location;
    _CONSOLE_SCREEN_BUFFER_INFO bi;
    GetConsoleScreenBufferInfo(outHandle, &bi);                         //gets the current location of the cursor
    location = bi.dwCursorPosition;
    /*check if cursor is in bounderies*/
    if (location.X + x >= this->left_limit && location.X + x < this->right_limit && location.Y + y >= this->top_limit && location.Y + y < this->bottom_limit) {
        location.X += x;
        location.Y += y;
        SetConsoleCursorPosition(outHandle, location);                  //set the new cursor location
        return true;
    }
    else
    {
        if (location.X + x == this->right_limit) {
            if (location.Y + y >= this->top_limit && location.Y + y < this->bottom_limit - 1) {
                location.X = this->left_limit;
                location.Y += 1;
                SetConsoleCursorPosition(outHandle, location);              //set the new cursor location
                return true;
            }
        }
        if (location.X + x == this->left_limit) {
            if (location.Y + y >= this->bottom_limit && location.Y + y < this->top_limit - 1) {
                location.X = this->right_limit;
                location.Y -= 1;
                SetConsoleCursorPosition(outHandle, location);              //set the new cursor location
                return true;
            }
        }
        if (location.X + x == this->left_limit - 1) {
            if (location.Y + y < this->bottom_limit && location.Y + y > this->top_limit) {
                location.X = this->right_limit - 1;
                location.Y -= 1;
                SetConsoleCursorPosition(outHandle, location);              //set the new cursor location
                return true;
            }
        }
        return false;
    }
}

void TextBox::eventListenr(char T) {
    DWORD colors = this->text_color | this->background_color;
    SetConsoleTextAttribute(outHandle, colors);         //set console textbox colors
    switch (T) {
        case 0x25:   //left arrow (VK_LEFT)
        {
            if (getAbsolutePosition() <= buffer.length()) {
                this->setCursor(-1, 0);
            }
            break;
        }
        case 0x27:  //right arrow (VK_RIGHT)
        {
            if (getAbsolutePosition() < buffer.length()) {
                this->setCursor(1, 0);
            }
            break;
        }
        case 0x26:  //up arrow (VK_UP)
        {
            if (getAbsolutePosition() - width < buffer.length() && getAbsolutePosition() - width >= 0) {
                this->setCursor(0, -1);
            }
            break;
        }
        case 0x28:  //down arrow (VK_DOWN)
        {
            if (getAbsolutePosition() + width <= buffer.length()) {
                this->setCursor(0, 1);
            }
            break;
        }
    case 0x08:   //backspace (VK_BACK)
    {
        if (buffer.length() == width * height) {
            printf(" ");
            setCursor(-1, 0);
            buffer.pop_back();
        }
        else {
            if (setCursor(-1, 0)) {
                printf(" ");
                setCursor(-1, 0);

                if (getAbsolutePosition() == buffer.length() - 1) {
                    buffer.pop_back();
                }
                else {
                    GetConsoleScreenBufferInfo(outHandle, &bi);        //gets the current location of the cursor
                    COORD prevLoc = bi.dwCursorPosition;
                    temp_str = buffer.substr(getAbsolutePosition() + 1, buffer.length() - 1);
                    buffer.erase(getAbsolutePosition(), 1);
                    for (int i = 0; i < temp_str.size(); ++i) {
                        if (setCursor(0, 0)) {
                            printf("%c", temp_str[i]);
                        }
                    }
                    if (setCursor(0, 0)) {
                        printf(" ");
                    }
                    SetConsoleCursorPosition(outHandle, prevLoc);
                }
            }
        }
        break;
    }
    case 0x2E: //delete (VK_DELETE)
    {
        cout << " ";
        setCursor(-1, 0);
        GetConsoleScreenBufferInfo(outHandle, &bi);        //gets the current location of the cursor
        COORD prevLoc = bi.dwCursorPosition;
        if (getAbsolutePosition() < buffer.length()) {        
            temp_str = buffer.substr(getAbsolutePosition() + 1, buffer.length() - 1);
            buffer.erase(getAbsolutePosition(), 1);
            for (int i = 0; i < temp_str.size(); ++i) {
                if (setCursor(0, 0)) {
                    printf("%c", temp_str[i]);
                }
            }
            if (bi.dwCursorPosition.X == right_limit - 1 && bi.dwCursorPosition.Y == bottom_limit - 1) { //check if  its the last cell in text box, then dont move cursor and break
                break;
            }
            if (bi.dwCursorPosition.X >= prevLoc.X && bi.dwCursorPosition.Y >= prevLoc.Y) {     
                if (setCursor(0, 0)) {
                    printf(" ");
                    SetConsoleCursorPosition(outHandle, prevLoc);                  //set the new cursor location
                }
            }
        }
        break;
    }
    case 0x0D: //enter (VK_RETURN)
    {
        break;
    }
    // case 0x1B: //Ecs (VK_ESCAPE) (uses to exit program)
    // {
    //     exit(0);
    // }
    default:
    {
        if (T >= 0x20 && T <= 0x7e) {               //check if alpha-numeric or signs charachters or spacebar
            if (setCursor(0, 0)) {
                if (buffer.length() < (width * height)) {  //check if its not the last cell in textbox
                    if (getAbsolutePosition() == buffer.length()) {
                        printf("%c", T);
                        buffer += T;                    //append 'T' to buffer
                    }
                    else {
                        GetConsoleScreenBufferInfo(outHandle, &bi);        //gets the current location of the cursor
                        COORD prevLoc = bi.dwCursorPosition;
                        temp_str = T + buffer.substr(getAbsolutePosition(), buffer.length() - 1);
                        buffer.erase(getAbsolutePosition(), buffer.length());
                        buffer = buffer + temp_str;
                        for (int i = 0; i < temp_str.size(); ++i) {
                            if (setCursor(0, 0)) {
                                printf("%c", temp_str[i]);
                            }
                        }
                        SetConsoleCursorPosition(outHandle, prevLoc);
                        setCursor(1, 0);
                    }
                }
                COORD location;
                GetConsoleScreenBufferInfo(outHandle, &bi);     //gets the current location of the cursor
                location = bi.dwCursorPosition;
                if (location.X >= right_limit && location.Y >= top_limit && location.Y < bottom_limit - 1) {    //check if end of row and there is still space to go next line
                    SetConsoleCursorPosition(outHandle, { (SHORT)left_limit,location.Y + 1 });
                    break;
                }
                if (location.X >= right_limit && location.Y >= top_limit && location.Y < bottom_limit) { //check if its the last cell in textbox
                    SetConsoleCursorPosition(outHandle, { (SHORT)right_limit - 1,location.Y }); //set the cursor on the last cell in textbox
                }
            }
            break;
        }
        else {
            break;
        }
    }
    }
}

int TextBox::getAbsolutePosition(){       //claculate and returns text buffer position from real cuesor location
    COORD loc;
    GetConsoleScreenBufferInfo(outHandle, &bi);  //gets the current location of the cursor
    loc = bi.dwCursorPosition;
    int lval= width- (right_limit - loc.X);
    int rval= loc.Y - top_limit;
    int pos = lval + (width * rval);
    return pos;
}

COORD TextBox::currentLocation() {
    COORD temp = getCoordinate();
    temp.X = temp.X + (buffer.length()% width);
    temp.Y = temp.Y + (buffer.length() / width);
    if (temp.Y >= height + getCoordinate().Y) {
        temp.X = width+getCoordinate().X -1;
        temp.Y = height + getCoordinate().Y -1;
    }
    return temp;
}