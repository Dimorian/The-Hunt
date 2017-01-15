#ifndef WORLD_H
#define WORLD_H

#include "terrain.h"

#define WIDTH 15
#define HEIGHT 15

class World
{
private:
    //Terrain-Typen
    Terrain grassTerrain_;
    Terrain blockTerrain_;

    Terrain* tiles_[WIDTH][HEIGHT];
public:
    World();

    Terrain* getTile(int x, int y);
};

#endif // WORLD_H
