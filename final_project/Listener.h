#include <string> 
#include <windows.h>
#include <iostream>
#include "Component.h"

class Listener {
   
    public:
        virtual void listener(Component* conponent) = 0;
};