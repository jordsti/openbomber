#ifndef MAPGENERATOR_H
#define MAPGENERATOR_H

#include "TileMap.h"

class MapGenerator
{
    public:
        MapGenerator();
        virtual ~MapGenerator();

        static TileMap* GenerateMap(int width, int height, int nbPaths);
    protected:
    private:
};

#endif // MAPGENERATOR_H
