#include <string> 
#include <windows.h>
#include <iostream>
#include "Component.h"
#include "ComboBox.h"
#include "Listener.h"
class ListenerShowList: public Listener {
   
    public:
        virtual void listener(Component* conponent) ;
};