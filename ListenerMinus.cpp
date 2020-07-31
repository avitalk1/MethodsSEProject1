#include "ListenerMinus.h"
void ListenerMinus::listener(Component* component){
    static_cast<NumericBox*>(component)->Decrease();
}