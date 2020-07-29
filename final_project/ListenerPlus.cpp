#include "ListenerPlus.h"
void ListenerPlus::listener(Component* conponent){
    static_cast<NumericBox*>(conponent)->Increase();
}