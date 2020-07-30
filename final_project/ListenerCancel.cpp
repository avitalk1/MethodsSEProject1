#include "ListenerCancel.h"

void ListenerCancel::listener(Component* component){
    static_cast<MessageBoxComp*>(component)->clickCancel();
}