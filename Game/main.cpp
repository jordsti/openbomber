#include <Viewport.h>
#include "MainMenuState.h"
#include "OpenBomberStyle.h"

using namespace StiGame;

int main(int argv, char** args)
{
    Viewport viewport = Viewport(800, 600);


    OpenBomberStyle* style = new OpenBomberStyle();

    Gui::Runtime::getInstance()->ForceStyle(style);

    MainMenuState mainMenu = MainMenuState();
    viewport.setFps(60);
    viewport.push(&mainMenu);
    viewport.startLoop();

    SDL_Quit();

    return 0;
}
