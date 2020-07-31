#pragma once
#include <windows.h>
#include <stdio.h>
#include <typeinfo>
#include "Panel.h"


class HandleIO {
	HANDLE outHandle;
	HANDLE hStdin;
	DWORD fdwSaveOldMode;
	DWORD cNumRead, fdwMode, i;
	INPUT_RECORD irInBuf[128];
	int counter;
	Panel* curr_panel;

		
	public:
	HandleIO();
	Panel* panel;
	 _CONSOLE_SCREEN_BUFFER_INFO bi;
	WORD prevAttribute;
		void setCurrPanel(Panel* p);
		HandleIO* init(Panel* panel);
		void ErrorExit(LPSTR);
		void KeyEventProc(KEY_EVENT_RECORD);
		// void addComponent(Component& c);
		void ResizeEventProc(WINDOW_BUFFER_SIZE_RECORD);
		void IOstart();
		void keyIdentifier(KEY_EVENT_RECORD ker);
		~HandleIO();
};

// HandleIO* IO = NULL;
// HandleIO* getIO();