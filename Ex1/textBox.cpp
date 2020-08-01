#include "textbox.h"

textBox::textBox(COORD coord, int width, int length) {
    this->coord = coord;
    this->width = width;
    this->length = length;
    this->leftLim = coord.X;
    this->rightLim = coord.X + width;
    this->upLim = coord.Y;
    this->downLim = coord.Y + length;
}

int textBox::getDownLim() { return this->downLim; }
int textBox::getUpLim() { return this->upLim; }
int textBox::getLeftLim() { return this->leftLim; }
int textBox::getRightLim() { return this->rightLim; }

void textBox::_draw() {
    COORD temp = coord;
    auto outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info = { 1, 0 };                 //set cursor invisible   Lvalue= size (1-100), Rvalue= setVisable(0 or 1)
    SetConsoleCursorInfo(outHandle, &info);             //hide input cursor
    SetConsoleCursorPosition(outHandle, coord);         //set console textbox coordinates
    SetConsoleTextAttribute(outHandle, colors);         //set console textbox colors
    for (int i = 0; i < this->length; ++i) {
        for (int k = 0; k < this->width; ++k) {
            cout << " ";
        }
        temp.Y += 1;
        SetConsoleCursorPosition(outHandle, temp);      //set console textbox coordinates
    }
    SetConsoleCursorPosition(outHandle, coord);         //set console cursor coordinates
    info = { 1, 1 };                                        //set cursor visible    Lvalue= size (1-100), Rvalue= setVisable(0 or 1)
    SetConsoleCursorInfo(outHandle, &info);              //show input cursor
}

bool textBox::SetCursor(int lr, int ud) {                              //set cursor location
    COORD location;
    _CONSOLE_SCREEN_BUFFER_INFO bi;
    GetConsoleScreenBufferInfo(outHandle, &bi);                         //gets the current location of the cursor
    location = bi.dwCursorPosition;
    /*check if cursor is in bounderies*/
    if (location.X + lr >= this->leftLim && location.X + lr < this->rightLim && location.Y + ud >= this->upLim && location.Y + ud < this->downLim) {
        location.X += lr;
        location.Y += ud;
        SetConsoleCursorPosition(outHandle, location);                  //set the new cursor location
        return true;
    }
    else
    {
        if (location.X + lr == this->rightLim) {
            if (location.Y + ud >= this->upLim && location.Y + ud < this->downLim - 1) {
                location.X = this->leftLim;
                location.Y += 1;
                SetConsoleCursorPosition(outHandle, location);              //set the new cursor location
                return true;
            }
        }
        if (location.X + lr == this->leftLim) {
            if (location.Y + ud >= this->downLim && location.Y + ud < this->upLim - 1) {
                location.X = this->rightLim;
                location.Y -= 1;
                SetConsoleCursorPosition(outHandle, location);              //set the new cursor location
                return true;
            }
        }
        if (location.X + lr == this->leftLim - 1) {
            if (location.Y + ud < this->downLim && location.Y + ud > this->upLim) {
                location.X = this->rightLim - 1;
                location.Y -= 1;
                SetConsoleCursorPosition(outHandle, location);              //set the new cursor location
                return true;
            }
        }
        return false;
    }
}

void textBox::_write(char T) {
    SetConsoleTextAttribute(outHandle, colors);         //set console textbox colors
    switch (T) {
        case 0x25:   //left arrow (VK_LEFT)
        {
            if (getAbsPos() <= buffer.length()) {
                this->SetCursor(-1, 0);
            }
            break;
        }
        case 0x27:  //right arrow (VK_RIGHT)
        {
            if (getAbsPos() < buffer.length()) {
                this->SetCursor(1, 0);
            }
            break;
        }
        case 0x26:  //up arrow (VK_UP)
        {
            if (getAbsPos() - width < buffer.length() && getAbsPos() - width >= 0) {
                this->SetCursor(0, -1);
            }
            break;
        }
        case 0x28:  //down arrow (VK_DOWN)
        {
            if (getAbsPos() + width <= buffer.length()) {
                this->SetCursor(0, 1);
            }
            break;
        }
    case 0x08:   //backspace (VK_BACK)
    {
        if (buffer.length() == width * length) {
            printf(" ");
            SetCursor(-1, 0);
            buffer.pop_back();
        }
        else {
            if (SetCursor(-1, 0)) {
                printf(" ");
                SetCursor(-1, 0);

                if (getAbsPos() == buffer.length() - 1) {
                    buffer.pop_back();
                }
                else {
                    GetConsoleScreenBufferInfo(outHandle, &bi);        //gets the current location of the cursor
                    COORD prevLoc = bi.dwCursorPosition;
                    tempStr = buffer.substr(getAbsPos() + 1, buffer.length() - 1);
                    buffer.erase(getAbsPos(), 1);
                    for (int i = 0; i < tempStr.size(); ++i) {
                        if (SetCursor(0, 0)) {
                            printf("%c", tempStr[i]);
                        }
                    }
                    if (SetCursor(0, 0)) {
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
        SetCursor(-1, 0);
        GetConsoleScreenBufferInfo(outHandle, &bi);        //gets the current location of the cursor
        COORD prevLoc = bi.dwCursorPosition;
        if (getAbsPos() < buffer.length()) {        
            tempStr = buffer.substr(getAbsPos() + 1, buffer.length() - 1);
            buffer.erase(getAbsPos(), 1);
            for (int i = 0; i < tempStr.size(); ++i) {
                if (SetCursor(0, 0)) {
                    printf("%c", tempStr[i]);
                }
            }
            if (bi.dwCursorPosition.X == rightLim - 1 && bi.dwCursorPosition.Y == downLim - 1) { //check if  its the last cell in text box, then dont move cursor and break
                break;
            }
            if (bi.dwCursorPosition.X >= prevLoc.X && bi.dwCursorPosition.Y >= prevLoc.Y) {     
                if (SetCursor(0, 0)) {
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
            if (SetCursor(0, 0)) {
                if (buffer.length() < (width * length)) {  //check if its not the last cell in textbox
                    if (getAbsPos() == buffer.length()) {
                        printf("%c", T);
                        buffer += T;                    //append 'T' to buffer
                    }
                    else {
                        GetConsoleScreenBufferInfo(outHandle, &bi);        //gets the current location of the cursor
                        COORD prevLoc = bi.dwCursorPosition;
                        tempStr = T + buffer.substr(getAbsPos(), buffer.length() - 1);
                        buffer.erase(getAbsPos(), buffer.length());
                        buffer = buffer + tempStr;
                        for (int i = 0; i < tempStr.size(); ++i) {
                            if (SetCursor(0, 0)) {
                                printf("%c", tempStr[i]);
                            }
                        }
                        SetConsoleCursorPosition(outHandle, prevLoc);
                        SetCursor(1, 0);
                    }
                }
                COORD location;
                GetConsoleScreenBufferInfo(outHandle, &bi);     //gets the current location of the cursor
                location = bi.dwCursorPosition;
                if (location.X >= rightLim && location.Y >= upLim && location.Y < downLim - 1) {    //check if end of row and there is still space to go next line
                    SetConsoleCursorPosition(outHandle, { (SHORT)leftLim,location.Y + 1 });
                    break;
                }
                if (location.X >= rightLim && location.Y >= upLim && location.Y < downLim) { //check if its the last cell in textbox
                    SetConsoleCursorPosition(outHandle, { (SHORT)rightLim - 1,location.Y }); //set the cursor on the last cell in textbox
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

int textBox::getAbsPos(){       //claculate and returns text buffer position from real cuesor location
    COORD loc;
    GetConsoleScreenBufferInfo(outHandle, &bi);  //gets the current location of the cursor
    loc = bi.dwCursorPosition;
    int lval= width- (rightLim - loc.X);
    int rval= loc.Y - upLim;
    int pos = lval + (width * rval);
    return pos;
}

COORD textBox::CurrLocation() {
    COORD temp = getCoord();
    temp.X = temp.X + (buffer.length()% width);
    temp.Y = temp.Y + (buffer.length() / width);
    if (temp.Y >= length + getCoord().Y) {
        temp.X = width+getCoord().X -1;
        temp.Y = length + getCoord().Y -1;
    }
    return temp;
}