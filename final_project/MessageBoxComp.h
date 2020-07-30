#pragma once
#include <string> 
#include <windows.h>
#include <iostream>
#include "Component.h"
#include "Button.h"
#include "Label.h"
#include "ListenerOk.h"
#include "ListenerCancel.h"
#include "HandleIO.h"

class MessageBoxComp : public Component {
    Label* label;
    Button* ok_button;
    Button* cancel_button;
    Button* curr_button;
    _CONSOLE_SCREEN_BUFFER_INFO bi;
protected:
    COORD ok_btn_position;
    COORD cancel_btn_position;
    COORD prevCursorLocation;

public:
    MessageBoxComp(int w, int h, COORD start_coord, DWORD bg_color, DWORD txt_color,string txt, Border border = NONE);
    void setLabel(string button_label);
    Label* getLabel();
    virtual void eventListener(char T);
    virtual void _draw();
    ~MessageBoxComp();
    bool clickOk();
    bool clickCancel();
    void cls( HANDLE hConsole ); //clear screen
    // void saveCurrentScreen();
    // void loadPrevScreen();
};