#include "warnedstate.h"
#include "animal.h"

WarnedState::WarnedState()
{
    sightRange_ = 6;
    smellRange_ = 4;
}

void WarnedState::update(Animal* animal)
{
    animal->sightingX_ = 0;
    animal->sightingY_ = 0;

    animal->smellSense();
    animal->sightSense();

    animal->move();
}

void WarnedState::move(Animal* animal)
{
    //TODO: Flucht in entgegengesetzte Sichtungsrichtung
}
