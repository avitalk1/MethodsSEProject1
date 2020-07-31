#pragma once
#include <string> 
#include <windows.h>
#include <iostream>
#include "ComboBox.h"
#include "Listener.h"
class ListenerShowList: public Listener { 
    public:
        virtual void listener(Component* conponent) ;
};