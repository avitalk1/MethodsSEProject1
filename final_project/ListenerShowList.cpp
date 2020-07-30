#include "ListenerShowList.h"

void ListenerShowList::listener(Component* conponent){
    static_cast<ComboBox*>(conponent)->setShowList();

}