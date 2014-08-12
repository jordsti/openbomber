#include "TileMap.h"

const int TileMap::DEFAULT_WIDTH = 64;
const int TileMap::DEFAULT_HEIGHT = 32;

TileMap::TileMap()
{
    //ctor
    tileWidth = 0;
    tileHeight = 0;
    width = DEFAULT_WIDTH;
    height = DEFAULT_HEIGHT;
    initTiles();
}

TileMap::TileMap(int m_width, int m_height)
{
    //ctor
    tileWidth = 0;
    tileHeight = 0;
    width = m_width;
    height = m_height;
    initTiles();
}

int TileMap::getWidth(void)
{
    return width;
}

int TileMap::getHeight(void)
{
    return height;
}

int TileMap::getTileWidth(void)
{
    return tileWidth;
}

int TileMap::getTileHeight(void)
{
    return tileHeight;
}

Tile* TileMap::getTile(int t_x, int t_y)
{
    return tiles[t_y][t_x];
}

void TileMap::initTiles()
{
    tileHeight = Tile::TILE_WIDTH;
    tileWidth = Tile::TILE_HEIGHT;

    for(int i=0; i<height; i++)
    {
        std::vector<Tile*> row_tiles;
        for(int j=0; j<width; j++)
        {
            Tile *tile = new Tile();
            row_tiles.push_back(tile);
        }
        tiles.push_back(row_tiles);
    }
}

TileMap::~TileMap()
{
    //dtor
    //todo
    //clear the tiles data
}
