#include "world.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

World::World(QString path)
    : grassTerrain_(false, true),
      blockTerrain_(true, false)
{

    //edited:
    meshs_.append(new TriangleMesh(path+QString("/../Models/Baum.obj")));
    meshs_.append(new TriangleMesh(path+QString("/../Models/Bodenblock.obj")));
    Material *m;
    Texture *t;
    ModelTransformation *trans;
    //




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
                    terrainDrawables_[i][j] = new Drawable(meshs_.at(0));
                    t = terrainDrawables_[i][j]->getProperty<Texture>();
                    t->loadPicture(path+QString("/../Textures/BaumTexture.png"));
                    terrainDrawables_[i][j]->setShader(ShaderManager::getShader(QString("://shaders/texture.vert"), QString("://shaders/texture.frag")));

                    //

                    std::cout<<"#";
                    break;
                case 2:
                    tiles_[i][j]=&blockTerrain_;

                    //edited:
                    terrainDrawables_[i][j] = new Drawable(meshs_.at(1));
                    t = terrainDrawables_[i][j]->getProperty<Texture>();
                    t->loadPicture(path+QString("/../Textures/BaumTexture.png"));
                    terrainDrawables_[i][j]->setShader(ShaderManager::getShader(QString("://shaders/texture.vert"), QString("://shaders/texture.frag")));

                    //

                    std::cout<<"O";
                    break;


            //Edited:
            m = terrainDrawables_[i][j]->getProperty<Material>();
            m->setDiffuse(1., 1., 1., 1.);
            m->setAmbient(.5, .5, .5, 1.);
            m->setSpecular(1., 1., 1., 1.);
            m->setShininess(80.);
            trans = terrainDrawables_[i][j]->getProperty<ModelTransformation>();
            trans->translate(i*2.0 -7.0, 0.0, j*2.0 - 7.0);
            //
            }

        }
        std::cout<<std::endl;
    }

}

Terrain* World::getTile(int x, int y)
{
    return tiles_[x][y];
}
