#pragma once
#include <string> 
#include <windows.h>
#include <iostream>
#include "Listener.h"
#include "MessageBoxComp.h"

class ListenerCancel :public Listener {
   
    public:
        virtual void listener(Component* component) ;
};