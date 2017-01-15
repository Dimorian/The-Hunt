#include "smellpool.h"

SmellPool::SmellPool()
{

}

void SmellPool::animate(int windX, int windY)
{
    for(int i = 0; i < POOLSIZE; i++)
        smelltokens_[i].animate(windX, windY);
}

void SmellPool::create(int intensity, bool effect)
{
    for(int i = 0; i < POOLSIZE; i++)
    {
        if(!smelltokens_[i].inUse()){
            smelltokens_[i].init(intensity, effect);
            return;
        }
    }
}

bool SmellPool::isSmell(int x, int y)
{
    for(int i = 0; i < POOLSIZE; i++)
        if(smelltokens_[i].getX()==x && smelltokens_[i].getY()==y){
            return true;
        }

    return false;
}
