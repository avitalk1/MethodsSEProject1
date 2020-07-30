#pragma once
#include <string> 
#include <windows.h>
#include <iostream>
#include "Component.h"
#include "Listener.h"
#include "MessageBoxComp.h"

class ListenerOk :public Listener {
   
    public:
        virtual void listener(Component* component) ;
};