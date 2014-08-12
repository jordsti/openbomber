#include "MapGenerator.h"
#include <cmath>
#include <list>
#include <Point.h>

using namespace StiGame;

MapGenerator::MapGenerator()
{
    //ctor
}

MapGenerator::~MapGenerator()
{
    //dtor
}

TileMap* MapGenerator::GenerateMap(int width, int height, int nbPaths)
{
    TileMap *tmap = new TileMap(width, height);
    for(int y=0; y<tmap->getHeight(); y++)
    {
        for(int x=0; x<tmap->getWidth(); x++)
        {
            //set all to block
            Tile *t = tmap->getTile(x, y);
            t->setTileType(TT_Block);
        }
    }

    //generating path

    for(int i=0; i<nbPaths; i++)
    {
        int start_x = 0;
        int start_y = 0;
        int dir = rand() % 4;

        if(dir == 0)
        {
            //top
            start_x = rand() % width;
        }
        else if(dir == 1)
        {
            //bottom
            start_y = height - 1;
            start_x = rand() % width;
        }
        else if(dir == 2)
        {
            //left
            start_y = rand() % height;
        }
        else if(dir == 3)
        {
            //right
            start_y = rand() % height;
            start_x = width - 1;
        }

        std::list<Point*> pathPts;
        Point *pt = new Point(start_x, start_y);
        pathPts.push_back(pt);

    }


}
