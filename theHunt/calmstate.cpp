#include "calmstate.h"
#include <time.h>
#include <stdlib.h>
#include <QVector>

#include "animal.h"
#include "warnedstate.h"

CalmState::CalmState()
{
    sightRange_ = 4;
    smellRange_ = 3;
}

AnimalState* CalmState::update(Animal* animal)
{
    if(animal->sightingX_ != 0 || animal->sightingY_ != 0)  //nicht optimal
        return new WarnedState;

    return NULL;
}

void CalmState::move(Animal* animal)
{
    srand(time(NULL));
    int xPos = animal->position_.x();
    int yPos = animal->position_.y();
    int xBuf, yBuf;

    /*
    do{
        xBuf = rand()%2-1;
        if(xBuf == 0)
            yBuf = rand()%2-1;
        else
            yBuf = 0;
    }while()

    //TODO: Zuweisung auf animal Position
    animal->position_.x() += xBuf;
    animal->position_.y() += yBuf;
    */
}
