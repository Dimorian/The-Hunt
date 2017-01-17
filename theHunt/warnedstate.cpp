#include "warnedstate.h"
#include "animal.h"
#include "calmstate.h"
#include "World.h"
#include <math.h>

WarnedState::WarnedState()
    : turnsLeft_ (2)
{
    sightRange_ = 6;
    smellRange_ = 4;
}

AnimalState* WarnedState::update(Animal* animal)
{
    turnsLeft_ --;

    if (turnsLeft_ <= 0)
        return new CalmState();

    return NULL;
}

void WarnedState::move(Animal* animal, World* world)
{
    //TODO: Flucht in entgegengesetzte Sichtungsrichtung
    float xPos = (animal->position_.x()+14)/2;
    float yPos = (animal->position_.z()+14)/2;

    QVector2D newDest(animal->sightingX_-xPos, animal->sightingY_-yPos);
    newDest.normalize();
    newDest *= -1.0f;

    QVector3D* newPos = new QVector3D(0.0f, 0.4f, 0.0f);
    float xBuf = roundf(newDest.x());
    float yBuf = roundf(newDest.y());

    //Direkt endgegengesetzte Richtung testen und ggf weiterleiten
    if(world->getTile(xBuf, yBuf)->getBegehbar()){
        newDest.setX(xBuf);
        newDest.setY(yBuf);
        animal->setRichtung(&newDest);
        newPos->setX((xPos+xBuf)*2-14);
        newPos->setZ((yPos+yBuf)*2-14);
        animal->setPosition(newPos);
        return;
    }
    //falls direkt entgegengesetzte Richtung nicht begehbar, bleibt das Tier stehen
}
