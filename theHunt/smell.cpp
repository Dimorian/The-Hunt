#include "smell.h"

Smell::Smell()
    : turnsLeft_(0)
{
}

void Smell::init(int intensity, bool effect)
{
    turnsLeft_=intensity;
    positiv_=effect;
}

void Smell::animate(int windX, int windY)
{
    if (inUse()){
        xPos_+=windX;
        yPos_+=windY;
    }
}

bool Smell::inUse() const
{
    return turnsLeft_>0;
}

