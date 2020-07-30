
#pragma once
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string>

// #include "Button.h"
// #include "CheckedOption.h"
#include "CheckList.h"
#include "ComboBox.h"
#include "Component.h" 
#include "HandleIO.h"
#include "Label.h"
#include "MessageBoxComp.h"
#include "NumericBox.h"
#include "Panel.h"
#include "RadioBox.h" 
#include "TextBox.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Panel* main_panel = new Panel({0,0}, BACKGROUND_BLUE, FOREGROUND_GREEN);

    //to add components to the console do: main_panel.addComponent(...)
    HandleIO* io = HandleIO::init(main_panel);
    io->IOstart();
    return 0;
}
