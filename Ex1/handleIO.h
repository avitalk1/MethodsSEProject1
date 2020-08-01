
#pragma once
#include <windows.h>
#include <stdio.h>
#include "comp.h"


class handleIO {

	HANDLE outHandle;
	HANDLE hStdin;
	DWORD fdwSaveOldMode;
	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];
	int counter;
	_CONSOLE_SCREEN_BUFFER_INFO bi;
	WORD prevAttribute;
	/************************************/
	int comp_counter;
	comp** compList;
	comp* currComp;
	int N_currComp;
	//DWORD clickColor=(BACKGROUND_GREEN | BACKGROUND_INTENSITY);    //

public:
	handleIO();
	void ErrorExit(LPSTR);
	void KeyEventProc(KEY_EVENT_RECORD);
	void addComp(comp& c);
	//void MouseEventProc(MOUSE_EVENT_RECORD);
	void ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
	void IOstart();
	// void buildConsole();
	void showComp();

	void keyIdentifier(KEY_EVENT_RECORD ker);

	//  bool SetCursor(int lr, int ud);
	// void updateLim(int up, int down, int left, int right);
	//bool checkBound();
	~handleIO();
};