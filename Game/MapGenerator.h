#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include "TileMap.h"

class MapGenerator
{
    public:
        MapGenerator();
        virtual ~MapGenerator();

        static TileMap* GenerateMap(int width, int height, int npPaths, int maxObstructions, int seed);
        static TileMap* GenerateMap(int width, int height, int nbPaths, int maxObstructions);
    protected:
    private:
};

#endif // MAPGENERATOR_H
