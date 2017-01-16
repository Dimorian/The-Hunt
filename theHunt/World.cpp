#include "world.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

World::World()
    : grassTerrain_(false, true),
      blockTerrain_(true, false)
{



    srand(time(NULL));
    int type = 0;
    for (int i = 0; i<WIDTH; i++)
    {
        for (int j = 0; j<HEIGHT; j++)
        {
            type = rand()%3;
            switch(type){
                case 0:
                case 1:
                    tiles_[i][j]=&grassTerrain_;

                    //edited:
                    terrainDrawables_[i][j] = 1;
                    //

                    std::cout<<"#";
                    break;
                case 2:
                    tiles_[i][j]=&blockTerrain_;

                    //edited:
                    terrainDrawables_[i][j] = 2;
                    //

                    std::cout<<"O";
                    break;
            }

        }
        std::cout<<std::endl;
    }

}

Terrain* World::getTile(int x, int y)
{
    return tiles_[x][y];
}

int World::getTileAt(int i, int j){

    return terrainDrawables_[i][j];

}
