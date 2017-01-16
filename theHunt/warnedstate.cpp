#include "warnedstate.h"
#include "animal.h"

WarnedState::WarnedState()
    : turnsLeft_ (2)
{
    sightRange_ = 6;
    smellRange_ = 4;
}

AnimalState* WarnedState::update(Animal* animal)
{
    animal->sightingX_ = 0;
    animal->sightingY_ = 0;

    animal->smellSense();
    animal->sightSense();

    turnsLeft_ --;
    //TODO: Übergang
}

void WarnedState::move(Animal* animal)
{
    //TODO: Flucht in entgegengesetzte Sichtungsrichtung
}
