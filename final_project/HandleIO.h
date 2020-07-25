
#pragma once
#include <windows.h>
#include <stdio.h>
#include "Component.h"
#include "Panel.h"

class HandleIO {
	HANDLE outHandle;
	HANDLE hStdin;
	DWORD fdwSaveOldMode;
	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];
	int counter;
	_CONSOLE_SCREEN_BUFFER_INFO bi;
	WORD prevAttribute;
    Panel* panel;
	private:
		HandleIO();
	public:
		static HandleIO* init(Panel* panel);
		void ErrorExit(LPSTR);
		void KeyEventProc(KEY_EVENT_RECORD);
		void addComponent(Component& c);
		void ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
		void IOstart();
		void keyIdentifier(KEY_EVENT_RECORD ker);
		~HandleIO();
};

HandleIO* IO = NULL;