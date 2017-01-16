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
    Terrain blockTerrain_;


    Terrain* tiles_[WIDTH][HEIGHT];

    //edited:
    Drawable* terrainDrawables_[WIDTH][HEIGHT];
    QList<TriangleMesh*> meshs_;
    //

public:

    //edited:  parameter ergänzt
    World(QString path);
    inline QList<Drawable*>* getDrawables();
    //

    Terrain* getTile(int x, int y);
};

inline QList<Drawable*>* World::getDrawables(){
    QList<Drawable*>* ptrs = new QList<Drawable*>;
    for (int i = 0; i<WIDTH; i++)
    {
        for (int j = 0; j<HEIGHT; j++)
        {
            ptrs->append(terrainDrawables_[i][j]);
        }
    }
    return ptrs;
}

#endif // WORLD_H
