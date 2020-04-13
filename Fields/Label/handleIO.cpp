

#include "handleIO.h"

handleIO::handleIO() {
    counter = 0;
    comp_counter = 0;
    compList = NULL;
    currComp = NULL;
    N_currComp = -1;
    outHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(outHandle, &bi);
    prevAttribute = bi.wAttributes;
}
handleIO::~handleIO() {
    if (compList != NULL) {
        delete[] compList;
    }
}
void handleIO::ErrorExit(LPSTR lpszMessage)
{

    fprintf(stderr, "%s\n", lpszMessage);

    // Restore input mode on exit.

    SetConsoleMode(hStdin, fdwSaveOldMode);

    ExitProcess(0);
}


void handleIO::KeyEventProc(KEY_EVENT_RECORD ker)
{
    printf("Key event: %c virtual key code: %d", ker.uChar.AsciiChar, ker.wVirtualKeyCode);

    if (ker.bKeyDown)
        printf("key pressed\n");
    else printf("key released\n");
}


void handleIO::ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD wbsr)
{
    printf("Resize event\n");
    printf("Console screen buffer is %d columns by %d rows.\n", wbsr.dwSize.X, wbsr.dwSize.Y);
}



void handleIO::addComp(comp& c) {
    if (compList == NULL) {
        compList = new comp * ();
        if (compList == NULL) {
            cerr << "alloc";
            exit(1);
        }
        this->N_currComp = 0;
        this->comp_counter = 1;
        compList[0] = &c;
        currComp = compList[0];
    }
    else {
        comp_counter++;

        comp** temp = new comp * [comp_counter]();
        if (temp == NULL) {
            cerr << "alloc";
            exit(1);
        }

        int i;
        for (i = 0; i < comp_counter - 1; i++) {
            temp[i] = compList[i];
        }
        temp[i] = &c;

        delete[] compList;
        compList = temp;

    }
}

void handleIO::showComp() {
    if (compList != NULL) {
        for (int i = 0; i < comp_counter; i++) {
            compList[i]->_draw();
            SetConsoleTextAttribute(outHandle, prevAttribute);      //set colors back to prev
        }
        CONSOLE_CURSOR_INFO info = { 1,1 };
        SetConsoleCursorInfo(outHandle, &info);
        SetConsoleCursorPosition(outHandle, this->currComp->getCoord());
    }
}

void handleIO::IOstart() {
    // Get the standard input handle. 
    showComp();
    hStdin = GetStdHandle(STD_INPUT_HANDLE);
    if (hStdin == INVALID_HANDLE_VALUE)
        cerr << "GetStdHandle";

    // Save the current input mode, to be restored on exit. 

    if (!GetConsoleMode(hStdin, &fdwSaveOldMode))
        cerr << "GetConsoleMode";

    // Enable the window and mouse input events. 

    fdwMode = ENABLE_WINDOW_INPUT;
    if (!SetConsoleMode(hStdin, fdwMode))
        cerr << "SetConsoleMode";

    // Loop to read and handle the next 100 input events. 

    while (counter++ <= 100)
    {
        // Wait for the events. 

        if (!ReadConsoleInput(
            hStdin,      // input buffer handle 
            irInBuf,     // buffer to read into 
            128,         // size of read buffer 
            &cNumRead)) // number of records read
            cerr << "ReadConsoleInput";

        // Dispatch the events to the appropriate handler. 

        for (i = 0; i < cNumRead; i++)
        {
            switch (irInBuf[i].EventType)
            {
            case KEY_EVENT: // keyboard input 
                //KeyEventProc(irInBuf[i].Event.KeyEvent);
                keyIdentifier(irInBuf[i].Event.KeyEvent);
                break;

                // case MOUSE_EVENT: // mouse input 
                //     MouseEventProc(irInBuf[i].Event.MouseEvent); 
                //     break; 

            //case WINDOW_BUFFER_SIZE_EVENT: // scrn buf. resizing 
            //    ResizeEventProc(irInBuf[i].Event.WindowBufferSizeEvent);
            //    break;

            //case FOCUS_EVENT:  // disregard focus events 

            //case MENU_EVENT:   // disregard menu events 
            //    break;

            default:
                //cerr << "Unknown event type";
                //ErrorExit("Unknown");
                break;
            }
        }
    }

    /*restore graphic configuration*/
    SetConsoleTextAttribute(outHandle, prevAttribute);      //set colors back to prev
    SetConsoleMode(hStdin, fdwSaveOldMode);                 // Restore input mode on exit.
}

void handleIO::keyIdentifier(KEY_EVENT_RECORD ker) {
    switch (ker.wVirtualKeyCode) {
    case 0x25:   //left arrow (VK_LEFT) (used in textBox controller)
    {
        if (ker.bKeyDown)
            currComp->_write(0x25);
        break;
    }
    case 0x27:  //right arrow (VK_RIGHT) (used in textBox controller)
    {
        if (ker.bKeyDown)
            currComp->_write(0x27);
        break;
    }
    case 0x26:  //up arrow (VK_UP) (used in textBox controller)
    {
        if (ker.bKeyDown)
            currComp->_write(0x26);

        break;
    }
    case 0x28:  //down arrow (VK_DOWN) (used in textBox controller)
    {
        if (ker.bKeyDown) {
            currComp->_write(0x28);
        }
        break;
    }
    case 0x09:    //tab (VK_TAB) (used to navigate between controllers)
    {
        if (ker.bKeyDown) {
            N_currComp++;
            if (N_currComp == comp_counter) {
                currComp = compList[0];
                N_currComp = 0;
            }
            else currComp = compList[N_currComp];
        }
        SetConsoleCursorPosition(outHandle, currComp->CurrLocation());

        /*restore graphic configuration*/
        /*maybe use FlushConsoleInputBuffer function() on each 'tab' click in order to clear the console input buffer?*/
        SetConsoleTextAttribute(outHandle, prevAttribute);      //set colors back to prev
        SetConsoleMode(hStdin, fdwSaveOldMode);                 // Restore input mode on exit.
        break;
    }
    case 0x08:   //backspace (VK_BACK) (used in textBox controller)
    {
        if (ker.bKeyDown) {
            currComp->_write(0x08);
        }
        break;
    }
    case 0x2E: //delete (VK_DELETE) (used in textBox controller)
    {
        if (ker.bKeyDown) {
            currComp->_write(0x2E);
        }
        break;
    }
    case 0x0D: //enter (VK_RETURN) (used in checkbox controller)
    {

        if (ker.bKeyDown) {
            currComp->_write(0x0D);
        }
        break;
    }
    case 0x20:  //spacebar(VK_SPACE) (used in textBox controller)
    {

        if (ker.bKeyDown) {
            currComp->_write(0x20);
        }
        break;
    }
    case 0x1B: //Ecs (VK_ESCAPE) (uses to exit program)
    {
        exit(0);
    }
    default:    // (used in textBox controller)
    {
        //if (ker.uChar == 0x11) {
        //    cout << "CTRL!!";
        //    break;
        //}
        if (ker.wVirtualKeyCode >= 0x21 && ker.wVirtualKeyCode <= 0x7e) {
            if (ker.bKeyDown) {
                currComp->_write(ker.uChar.AsciiChar);
            }
        }
        break;
    }
    }
}
