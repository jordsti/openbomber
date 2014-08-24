#include "GameState.h"
#include "MapGenerator.h"
#include <Viewport.h>
#include <iostream>
using namespace StiGame;

GameState::GameState() :
    BaseGameState()
{
    //ctor
    view_x = 0;
    view_y = 0;
    initiated = false;
}

void GameState::onPaint(SDL_Renderer *renderer)
{
    renderBackgroundMap(renderer);
}

void GameState::renderBackgroundMap(SDL_Renderer *renderer)
{
    int tile_start_x = view_x / tileMap->getTileWidth();
    int tile_start_y = view_y / tileMap->getTileHeight();
    int offset_x = view_x % tileMap->getTileWidth();
    int offset_y = view_y % tileMap->getTileHeight();

    //int tiles_w = (width / tileMap->getTileWidth()) + 1;
    //int tiles_h = (height / tileMap->getTileHeight()) + 1;
    MPoint pt = MPoint();
    Sprite *spr;
    for(int y=tile_start_y; y<tileMap->getHeight(); y++)
    {
        for(int x=tile_start_x; x<tileMap->getWidth(); x++)
        {
            Tile *t = tileMap->getTile(x, y);
            pt.setPoint(x*tileMap->getTileWidth() + offset_x, y*tileMap->getTileHeight() + offset_y);
            if(t->getTileType() == TT_Normal)
            {
                spr = sprites.getSprite("normal_tile");
            }
            else
            {
                spr = sprites.getSprite("block_tile");
            }

            spr->setPoint(&pt);
            spr->render();
        }
    }
}

void GameState::onStart(void)
{
    running = true;
    initGame();
}

void GameState::initGame(void)
{
    sprites = SpriteLibrary(getViewport()->getRenderer());
    tileMap = MapGenerator::GenerateMap(128, 64, 8, 10);
    sprites.loadVarFile("normal_tile");
    sprites.loadVarFile("block_tile");
}

GameState::~GameState()
{
    //dtor
}
