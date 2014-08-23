#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <BaseGameState.h>
#include <SpriteLibrary.h>
#include "TileMap.h"

class GameState :
    public StiGame::BaseGameState
{
    public:
        GameState();
        virtual ~GameState();
        void initGame(void);
    protected:
        void onPaint(SDL_Renderer *renderer);
        void renderBackgroundMap(SDL_Renderer *renderer);
    private:
        bool initiated;
        TileMap *tileMap;
        StiGame::SpriteLibrary sprites;
        int view_x;
        int view_y;

};

#endif // GAMESTATE_H
