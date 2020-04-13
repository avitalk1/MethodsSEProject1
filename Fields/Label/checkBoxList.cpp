
#include "checkBoxList.h"

checkBoxList::checkBoxList(string headLine, COORD coord, string *ops, int ops_num)
{
    checkBoxOps = NULL;
    this->headLine = headLine;
    setCoord(coord);
    setOps(ops, ops_num);
    this->curr = 0;
}

void checkBoxList::_draw()
{
    SetConsoleCursorPosition(outHandle, coord); //set console checkbox coordinates
    SetConsoleTextAttribute(outHandle, colors); //set console checkbox colors
    cout << headLine;
    for (int i = 0; i < ops_num; i++)
    {
        checkBoxOps[i].draw(outHandle);
        SetConsoleCursorPosition(outHandle, checkBoxOps[i].getCoord());
    }
    _move(0);
}

void checkBoxList::_move(int y)
{
    curr += y;
    if (curr < 0)
    {
        curr = ops_num - 1;
    }
    if (curr == ops_num)
    {
        curr = 0;
    }
    SetConsoleCursorPosition(outHandle, checkBoxOps[curr].getCoord()); //set the cursor location
}

void checkBoxList::_write(char T)
{
    if (T == 0x0D)
    {
        checkBoxList::selectOp();
    }
    if (T == 0x26)
    {
        _move(-1);
    }
    if (T == 0x28)
    {
        _move(1);
    }
}

void checkBoxList::selectOp()
{
    if (this->checkBoxOps != NULL)
    {
        this->checkBoxOps[curr].setCheck(outHandle);
    }
}

void checkBoxList::setheadLine(string headLine)
{
    this->headLine = headLine;
}
string checkBoxList::getheadLine()
{
    return this->headLine;
}

string *checkBoxList::getOps()
{
    return this->ops;
}
int checkBoxList::getOpsNum()
{
    return this->ops_num;
}

void checkBoxList::setOps(string *ops, int num)
{
    if (NULL != checkBoxOps)
    {
        delete[] checkBoxOps;
    }
    this->ops = ops;
    this->ops_num = num;
    if (ops_num > 0)
    {
        this->checkBoxOps = new checkBox[ops_num]();
        if (checkBoxOps == NULL)
        {
            cerr << "alloc";
            exit(1);
        }
        for (int i = 0; i < ops_num; i++)
        {
            checkBoxOps[i].setText(ops[i]);
            checkBoxOps[i].setCoord({this->coord.X, (SHORT)(this->coord.Y + ((i + 1) * 2))});
        }
    }
}

checkBoxList::~checkBoxList()
{
    if (this->checkBoxOps != NULL)
    {
        delete[] checkBoxOps;
    }
}
void checkBoxList::setColors(DWORD fg, DWORD bg)
{
    this->colors = fg | bg;
    for (int i = 0; i < ops_num; i++)
    {
        checkBoxOps[i].setColors(this->getColors());
    }
}

COORD checkBoxList::CurrLocation()
{
    return this->checkBoxOps[curr].getCoord();
}