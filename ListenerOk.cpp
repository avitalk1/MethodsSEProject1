#include "ListenerOk.h"

void ListenerOk::listener(Component* component){
    static_cast<MessageBoxComp*>(component)->clickOk();
}