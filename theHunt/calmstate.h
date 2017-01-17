#ifndef CALMSTATE_H
#define CALMSTATE_H

#include "animalstate.h"

class Animal;

class CalmState : public AnimalState
{
public:
    CalmState();

    AnimalState* update(Animal* animal);
    void move(Animal* animal, World* world);
};

#endif // CALMSTATE_H
