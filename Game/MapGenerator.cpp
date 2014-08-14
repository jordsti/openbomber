#include "MapGenerator.h"
#include <cmath>
#include <list>
#include <Point.h>
#include <MPoint.h>
#include <iostream>
#include <TimeTools.h>

using namespace StiGame;

MapGenerator::MapGenerator()
{
    //ctor
}

MapGenerator::~MapGenerator()
{
    //dtor
}


TileMap* MapGenerator::GenerateMap(int width, int height, int nbPaths, int maxObstructions)
{
    int seed = Time::GenerateSeed();
    return GenerateMap(width, height, nbPaths, maxObstructions, seed);
}

TileMap* MapGenerator::GenerateMap(int width, int height, int nbPaths, int maxObstructions, int seed)
{
    srand(seed);
    std::cout << "Seed : " << seed << std::endl;
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
    int nb_obs_count = 0;
    for(int i=0; i<nbPaths; i++)
    {
        int start_x = 0;
        int start_y = 0;
        int dir = rand() % 6;
        int end_x = 0;
        int end_y = 0;

        if(dir == 0)
        {
            //top
            start_x = rand() % width;
            start_y = 0;
            end_x = rand() % width;
            end_y = height - 1;
        }
        else if(dir == 1)
        {
            //bottom
            start_y = height - 1;
            start_x = rand() % width;
            end_x = rand() % width;
            end_y = 0;
        }
        else if(dir == 2)
        {
            //left
            start_y = rand() % height;
            start_x = 0;
            end_y = rand() % height;
            end_x = width - 1;
        }
        else if(dir == 3)
        {
            //right
            start_y = rand() % height;
            start_x = width - 1;
            end_y = rand() % height;
            end_x = 0;
        }
        else if(dir == 4)
        {
            start_x = 0;
            start_y = 0;
            end_x = width - 1;
            end_y = height - 1;
        }
        else if(dir == 5)
        {
            start_x = 0;
            start_y = height - 1;
            end_x = width - 1;
            end_y = 0;
        }

        std::list<Point*> pathPts;

        Point *start_pt = new Point(start_x, start_y);
        Point *end_pt = new Point(end_x, end_y);

        MPoint *current_pt = new MPoint(start_x, start_y);

        pathPts.push_back(start_pt);

        while(!current_pt->equals(end_pt))
        {
            int diff_x = end_pt->getX() - current_pt->getX();
            int diff_y = end_pt->getY() - current_pt->getY();



            if(std::abs(diff_x) > 0 && std::abs(diff_y) > 0)
            {
                int np_dir = rand() % 2;

                if(np_dir == 0)
                {
                    //x
                    if(diff_x < 0)
                    {
                        current_pt->setX(current_pt->getX() - 1);
                    }
                    else
                    {
                        current_pt->setX(current_pt->getX() + 1);
                    }
                }
                else
                {
                    //y
                    if(diff_y < 0)
                    {
                        current_pt->setY(current_pt->getY() - 1);
                    }
                    else
                    {
                        current_pt->setY(current_pt->getY() + 1);
                    }
                }

            }
            else if(std::abs(diff_x) > 0)
            {
                    if(diff_x < 0)
                    {
                        current_pt->setX(current_pt->getX() - 1);
                    }
                    else
                    {
                        current_pt->setX(current_pt->getX() + 1);
                    }
            }
            else
            {
                    if(diff_y < 0)
                    {
                        current_pt->setY(current_pt->getY() - 1);
                    }
                    else
                    {
                        current_pt->setY(current_pt->getY() + 1);
                    }

            }

            //pushing points
            Point *new_pt = new Point(current_pt->getX(), current_pt->getY());
            pathPts.push_back(new_pt);

        }

        //changing tile for normal
        std::list<Point*>::iterator lit(pathPts.begin()), lend(pathPts.end());
        for(;lit!=lend;++lit)
        {
            Tile *t = tmap->getTile((*lit)->getX(), (*lit)->getY());
            if(nb_obs_count < maxObstructions)
            {
                int obs = rand() % 10;
                if(obs > 1)
                {
                    t->setTileType(TT_Normal);
                }
                else
                {
                    nb_obs_count++;
                }
            }
            else
            {
                t->setTileType(TT_Normal);
            }


            delete (*lit);
        }

        //free list point

        delete end_pt;
        delete current_pt;

    }

    return tmap;
}
