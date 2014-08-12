#ifndef TILEMAP_H
#define TILEMAP_H

#include <vector>
#include "Tile.h"

class TileMap
{
    public:
        static const int DEFAULT_WIDTH;
        static const int DEFAULT_HEIGHT;

        TileMap();
        TileMap(int m_width, int m_height);
        virtual ~TileMap();

        int getWidth(void);
        int getHeight(void);

        int getTileWidth(void);
        int getTileHeight(void);

        Tile* getTile(int t_x, int t_y);

    protected:
        int width;
        int height;
        int tileWidth;
        int tileHeight;
        std::vector<std::vector<Tile*>> tiles;
    private:
        void initTiles(void);
};

#endif // TILEMAP_H
