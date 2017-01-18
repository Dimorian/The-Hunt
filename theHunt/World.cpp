#include "world.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

World::World()
    : grassTerrain_(false, true),
      baumTerrain_(true, false),
      tanneTerrain_(true, false),
      steinTerrain_(true, false)
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
                    std::cout<<'#';

                    //edited:
                    terrainDrawables_[i][j] = 1;
                    //
                    break;
                case 2:
                    type = rand()%5;
                    switch(type){
                        case 0:
                        case 3:
                            tiles_[i][j]=&baumTerrain_;
                            std::cout<<'O';
                            //edited:
                            terrainDrawables_[i][j] = 2;
                            //
                            break;
                        case 1:
                        case 4:
                            tiles_[i][j]=&tanneTerrain_;
                            std::cout<<'A';
                            //edited:
                            terrainDrawables_[i][j] = 3;
                            //
                            break;
                        case 2:
                            tiles_[i][j]=&steinTerrain_;
                            std::cout<<'S';
                            //edited:
                            terrainDrawables_[i][j] = 4;
                            //
                            break;
                    }
                }
        }
        std::cout<<std::endl;
    }
}

Terrain* World::getTile(int x, int y)
{
    if(x >= 0 && x<=WIDTH)
        if(x >= 0 && x<=HEIGHT)
            return tiles_[x][y];
    return &baumTerrain_;
}

int World::getTileAt(int i, int j){

    return terrainDrawables_[i][j];

}
