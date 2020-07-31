#include "ListenerPlus.h"
void ListenerPlus::listener(Component* component){
    static_cast<NumericBox*>(component)->Increase();
}