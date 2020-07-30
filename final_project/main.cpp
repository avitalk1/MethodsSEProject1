// #include "HandleIO.h"
// #include <windows.h>
// #include <stdio.h>
// #include <iostream>
// #include <string>
// using namespace std;

// int main(int argc, char const *argv[])
// {
//     // Panel main_panel({0,0}, )
//     // return 0;
// }




// #include "handleIO.h"
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "TextBox.h"
#include "Component.h"
// #include "checkList.h"
// #include "textBox.h"
// #include "Label.h"

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "try";
    DWORD TC = FOREGROUND_RED;
    DWORD BC = BACKGROUND_BLUE;
    TextBox* t = new TextBox(3,3,{0,0},TC,BC,NONE);
    // TextBox t2(3,3,{0,0},FOREGROUND_RED,BACKGROUND_BLUE,NONE);
    // t2->_draw();
    t->_draw();
    cout << "END";
    // TextBox* T= new TextBox(3,3,{0,0},FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY,BACKGROUND_BLUE,NONE);
    // TextBox tb1({5, 15}, 13, 2);
    // tb1.setColors(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY, BACKGROUND_BLUE);
    // string s = "head";
    // string list[5];
    // for (int i = 0; i < 5; i++)
    // {
    //     list[i] = "op" + to_string(i + 1);
    // }
    // checkBox l1(s, {1, 1}, list, 5);
    // l1.setColors(FOREGROUND_RED, BACKGROUND_GREEN | BACKGROUND_RED);
    // Label t("hello world", {5, 19});
    // t.setColors(FOREGROUND_GREEN, BACKGROUND_BLUE | BACKGROUND_RED);

    // HandleIO io;

    // io.addComp(tb1);
    // io.addComp(l1);
    // io.addComp(t);

    // io.IOstart();
    /* code */

    return 0;
}
