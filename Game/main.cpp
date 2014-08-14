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

    TileMap *tmap = MapGenerator::GenerateMap(64, 32, 6, 6);

    /*for(int i=0; i<tmap->getHeight(); i++)
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
    }*/

    Surface *map_sur = new Surface(tmap->getWidth()*tmap->getTileWidth(), tmap->getHeight()*tmap->getTileHeight());

    Color *bg = new Color(0, 0, 0);
    map_sur->fill(bg);

    Color *c1 = new Color();
    c1->setRGB(255, 0, 0);
    Color *c2 = new Color();
    c2->setRGB(0, 0, 255);
    Rectangle *rect = new Rectangle();
    rect->setDimension(tmap->getTileWidth(), tmap->getTileHeight());

    for(int y=0; y<tmap->getHeight(); y++)
    {
        for(int x=0; x<tmap->getWidth(); x++)
        {
            Color *to_use = c2;
            Tile *t = tmap->getTile(x, y);
            if(t->getTileType() == TT_Block)
            {
                to_use = c1;
            }

            rect->setPoint(x*tmap->getTileWidth(), y*tmap->getTileHeight());

            map_sur->fillRect(rect, to_use);
        }
    }

    map_sur->saveBmp("map_test.bmp");

    OpenBomberStyle* style = new OpenBomberStyle();

    Gui::Runtime::getInstance()->ForceStyle(style);

    MainMenuState mainMenu = MainMenuState();
    viewport.setFps(60);
    viewport.push(&mainMenu);
    viewport.startLoop();

    SDL_Quit();

    return 0;
}
