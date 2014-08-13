#include <Viewport.h>
#include "MainMenuState.h"
#include "OpenBomberStyle.h"
#include "TileMap.h"
#include "MapGenerator.h"
#include <iostream>
using namespace StiGame;

int main(int argv, char** args)
{
    Viewport viewport = Viewport(800, 600);

    //test tile map

    TileMap *tmap = MapGenerator::GenerateMap(64, 32, 4, 4);

    for(int i=0; i<tmap->getHeight(); i++)
    {
        std::cout << i << " : ";
        for(int j=0; j<tmap->getWidth(); j++)
        {
            Tile *t = tmap->getTile(j, i);
            if(t->getTileType() == TT_Normal)
            {
                std::cout << "N\t";
            }
            else if(t->getTileType() == TT_Block)
            {
                std::cout << "B\t";
            }
        }

        std::cout << std::endl;
    }


    OpenBomberStyle* style = new OpenBomberStyle();

    Gui::Runtime::getInstance()->ForceStyle(style);

    MainMenuState mainMenu = MainMenuState();
    viewport.setFps(60);
    viewport.push(&mainMenu);
    viewport.startLoop();

    SDL_Quit();

    return 0;
}
