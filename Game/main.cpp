#include <Viewport.h>
#include "MainMenuState.h"

using namespace StiGame;

int main(int argv, char** args)
{
    Viewport viewport = Viewport(800, 600);

    MainMenuState mainMenu = MainMenuState();
    viewport.setFps(60);
    viewport.push(&mainMenu);
    viewport.startLoop();

    SDL_Quit();

    return 0;
}
