#ifndef CALMSTATE_H
#define CALMSTATE_H

#include "animalstate.h"

class Animal;

class CalmState : public AnimalState
{
public:
    CalmState();

    void update(Animal* animal);
    void move(Animal* animal);
};

#endif // CALMSTATE_H
