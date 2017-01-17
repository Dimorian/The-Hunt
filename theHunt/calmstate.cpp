#include "calmstate.h"
#include <time.h>
#include <stdlib.h>
#include <QVector>

#include "animal.h"
#include "warnedstate.h"
#include "World.h"

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

void CalmState::move(Animal* animal, World* world)
{
    srand(time(NULL));
    int xPos = (animal->position_.x()+14)/2;
    int yPos = (animal->position_.z()+14)/2;
    int xBuf, yBuf;

    do{
        xBuf = rand()%2-1;
        if(xBuf == 0)
            yBuf = rand()%2-1;
        else
            yBuf = 0;
    }while(!world->getTile(xPos+xBuf, yPos+yBuf)->getBegehbar());

    QVector3D* newPosition = new QVector3D(float((xPos+xBuf)*2-14), 0.4f, float((yPos+yBuf)*2-14));
    animal->setPosition(newPosition);
    QVector2D* newDest = new QVector2D(float(xBuf), float(yBuf));
    animal->setRichtung(newDest);
}
