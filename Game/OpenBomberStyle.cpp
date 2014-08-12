#include "OpenBomberStyle.h"

using namespace StiGame;
using namespace Gui;

OpenBomberStyle::OpenBomberStyle() : Style()
{
    //ctor
    background.setRGB(56, 71, 68);
    foreground.setRGB(188, 224, 217);
    highlightBackground.setRGB(235, 153, 82);
    highlightForeground.setRGB(105, 22, 9);
}

OpenBomberStyle::~OpenBomberStyle()
{
    //dtor
}
