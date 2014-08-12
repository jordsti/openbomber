#include "Tile.h"


//constants
const int Tile::TILE_WIDTH = 32;
const int Tile::TILE_HEIGHT = 32;

Tile::Tile()
{
    //ctor
    tileType = TT_Normal;
    tileGraphic = "none";
}

Tile::Tile(TileType m_tileType, std::string m_tileGraphic)
{
    //ctor
    tileType = m_tileType;
    tileGraphic = m_tileGraphic;
}

std::string Tile::getTileGraphic()
{
    return tileGraphic;
}

TileType Tile::getTileType()
{
    return tileType;
}

void Tile::setTileGraphic(std::string m_tileGraphic)
{
    tileGraphic = m_tileGraphic;
}

void Tile::setTileType(TileType m_tileType)
{
    tileType = m_tileType;
}

Tile::~Tile()
{
    //dtor
}
