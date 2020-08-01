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
// #include "MessageBoxComp.h"
#include "NumericBox.h"
#include "Panel.h"
#include "RadioBox.h" 
#include "TextBox.h"

using namespace std;

int main(int argc, char const *argv[])
{
    
    // cout << "Start:\n";
    // cout << "wait";
    HandleIO* io = new HandleIO();
    Panel* main_panel = new Panel(io,{0,0}, BACKGROUND_BLUE, FOREGROUND_GREEN,DOUBLE_LINE,10,40);
    Panel* p2 = new Panel(io,{2,2}, BACKGROUND_RED, FOREGROUND_GREEN,DOUBLE_LINE,0,15);
    Panel* p3 = new Panel(io,{0,32}, BACKGROUND_GREEN, FOREGROUND_GREEN,DOUBLE_LINE,0,15);
    string s = "Radio box list";
    string list[2];
    for (int i = 0; i < 2; i++)
    {
        list[i] = "op" + to_string(i + 1);
    }
    RadioBox* radio_box = new RadioBox(1,1,{3,3},BACKGROUND_GREEN | BACKGROUND_RED,FOREGROUND_RED,s,list,2,SINGLE_LINE);
    string s2 = "checked list";
    string list2[3];
    for (int i = 0; i < 3; i++)
    {
        list[i] = "op" + to_string(i + 1);
    }
    CheckList* check = new CheckList(1,1,{3,11},BACKGROUND_GREEN | BACKGROUND_RED,FOREGROUND_RED,s2,list2,3,SINGLE_LINE);
    p2->addComponent(radio_box);
    p2->addComponent(check);
    main_panel->addComponent(p2);
    string s3 ="Combo box list";
    ComboBox* combo = new ComboBox(1,1,{2,34},BACKGROUND_RED,FOREGROUND_GREEN,s3,list2,3);

     
    string t="this is a label";
    Label* lab= new Label({1,25},BACKGROUND_RED,FOREGROUND_GREEN,t);
    Label* lab2= new Label({1,26},BACKGROUND_RED,FOREGROUND_GREEN,"this is textBox V");
    TextBox* tb = new TextBox(8,3,{1,28},BACKGROUND_GREEN,FOREGROUND_RED,NONE);
    main_panel->addComponent(lab);
    main_panel->addComponent(lab2);
    main_panel->addComponent(tb);
    p3->addComponent(combo);
    main_panel->addComponent(p3);
    
    Label* lab3= new Label({1,54},BACKGROUND_RED,FOREGROUND_GREEN,"this is NumericBox V");
    NumericBox* nb = new NumericBox(1,1,{1,56},BACKGROUND_RED,FOREGROUND_GREEN,1,20);
    main_panel->addComponent(lab3);
    main_panel->addComponent(nb);
    // string s = "head";
    // string list[5];
    // for (int i = 0; i < 5; i++)
    // {
    //     list[i] = "op" + to_string(i + 1);
    // }
    // RadioBox* radio_box = new RadioBox(1,1,{5,5},BACKGROUND_GREEN | BACKGROUND_RED,FOREGROUND_RED,s,list,5,SINGLE_LINE);
    // CheckList* ch = new CheckList(1,1,{1,8},BACKGROUND_GREEN | BACKGROUND_RED,FOREGROUND_RED,s,list,5,SINGLE_LINE);
    // ComboBox* b = new ComboBox(1,1,{1,20},BACKGROUND_RED,FOREGROUND_GREEN,s,list,5);
    // Panel* p2 = new Panel(io,{1,2}, BACKGROUND_GREEN, FOREGROUND_RED,DOUBLE_LINE);
    // p2->addComponent(nb12);
    // p2->addComponent(nb1);
    
    // main_panel->addComponent(nb);
    // main_panel->addComponent(p2);
    // main_panel->addComponent(nb2);
    
    // // main_panel->addComponent(radio_box);
    // main_panel->addComponent(nb);
    // main_panel->addComponent(tb);
    // main_panel->addComponent(ch);
    
    // //to add components to the console do: main_panel.addComponent(...)
    io = io->init(main_panel);
 
     io->IOstart();
   

    // cout << "Start:\n";
    // cout << "wait.\n";
    // TextBox* t = new TextBox(3,3,{0,0},BACKGROUND_BLUE,FOREGROUND_RED,DOUBLE_LINE);
    //V t->_draw();
    // Label* l= new Label({0,0},BACKGROUND_RED,FOREGROUND_GREEN,"text123");
    //V l->_draw();

    // NumericBox* nb = new NumericBox(1,1,{1,1},BACKGROUND_RED,FOREGROUND_GREEN,10,1,20);
    // nb->_draw();
    // std::string number  = std::
    cout<<"radio selected: op " + to_string(*(radio_box->getInput())+1);
    int * res = check->getInput();
    cout<<"CheckList selected:  ";
    for(int i=0; i < check->getNumberOfOptions() ;i++){
        if(res[i]==1){
            cout<<"OP"<<i+1<<",";
        }
    }
    cout<<"TextBox input is: "<<tb->getInput();
    cout<<"combobox selected: op " + to_string(*(combo->getInput())+1);
    cout<<"Numaricbox value: "<< to_string(nb->getValue());


    // cout << "end\n";
    // cout << "waitEnd.";
    return 0;
}
