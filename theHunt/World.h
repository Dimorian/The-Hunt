#ifndef WORLD_H
#define WORLD_H

#include "terrain.h"

//edited:
#include "qlist.h"
#include "drawable.h"
#include "trianglemesh.h"
#include "node.h"
#include "texture.h"
#include "material.h"
#include "shadermanager.h"
#include "modeltransformation.h"

//


#define WIDTH 15
#define HEIGHT 15

class World
{
private:
    //Terrain-Typen
    Terrain grassTerrain_;
    Terrain baumTerrain_;
    Terrain tanneTerrain_;
    Terrain steinTerrain_;


    Terrain* tiles_[WIDTH][HEIGHT];

    //edited:
    int terrainDrawables_[WIDTH][HEIGHT];
    //

public:

    //edited:
    World();
    int getTileAt(int i, int j);
    //
    Terrain* getTile(int x, int y);
};



#endif // WORLD_H
