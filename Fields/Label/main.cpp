#include "handleIO.h"
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "checkBoxList.h"
#include "textBox.h"
#include "Label.h"

using namespace std;

int main(int argc, char const *argv[])
{

    textBox tb1({5, 15}, 13, 2);
    tb1.setColors(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY, BACKGROUND_BLUE);
    string s = "head";
    string list[5];
    for (int i = 0; i < 5; i++)
    {
        list[i] = "op" + to_string(i + 1);
    }
    checkBoxList l1(s, {1, 1}, list, 5);
    l1.setColors(FOREGROUND_RED, BACKGROUND_GREEN | BACKGROUND_RED);
    Label t("hello world", {5, 19});
    t.setColors(FOREGROUND_GREEN, BACKGROUND_BLUE | BACKGROUND_RED);

    handleIO io;

    io.addComp(tb1);
    io.addComp(l1);
    io.addComp(t);

    io.IOstart();
    /* code */

    return 0;
}
