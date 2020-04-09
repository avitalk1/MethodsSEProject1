#include <Windows.h>
#include "Label.h"

int main(int argc, char const *argv[])
{
    Label label("hello world",{4,6});
    label.setColors(FOREGROUND_BLUE ,BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED|BACKGROUND_INTENSITY);
    label.draw();
    return 0;
}
