
#pragma once
#include <string>
#include <windows.h>
#include <iostream>
#include "checkBox.h"
#include "comp.h"



using namespace std;

class checkBoxList : public comp {
    string headLine;
    string* ops;
    int ops_num;
    int curr;
    checkBox* checkBoxOps;





public:
    checkBoxList(string headLine, COORD coord, string* ops, int ops_num);
    void setColors(DWORD fg, DWORD bg);
    virtual COORD CurrLocation();

    virtual void _draw();
    virtual void _write(char T);
    void _move(int y);



    void selectOp();
    void setheadLine(string headLine);
    string getheadLine();

    void setOps(string* ops, int ops_num);
    int getOpsNum();
    string* getOps();

    ~checkBoxList();


};