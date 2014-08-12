#ifndef TILE_H
#define TILE_H

#include <string>

enum TileType {
    TT_Normal,
    TT_Block
};

class Tile
{
    public:
        static const int TILE_WIDTH;
        static const int TILE_HEIGHT;

        Tile();
        Tile(TileType m_tileType, std::string m_tileGraphic);
        virtual ~Tile();

        std::string getTileGraphic(void);
        TileType getTileType(void);

        void setTileGraphic(std::string m_tileGraphic);
        void setTileType(TileType m_tileType);

    protected:
        std::string tileGraphic;
        TileType tileType;
    private:
};

#endif // TILE_H
