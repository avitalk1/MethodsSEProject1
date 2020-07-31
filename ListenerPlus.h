#pragma once
#include <string> 
#include <windows.h>
#include <iostream>
#include "Component.h"
#include "Listener.h"
#include "NumericBox.h"

class ListenerPlus :public Listener {
   
    public:
        virtual void listener(Component* component) ;
};