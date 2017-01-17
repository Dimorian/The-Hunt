#ifndef WARNEDSTATE_H
#define WARNEDSTATE_H

#include "animalstate.h"

class Animal;

class WarnedState : public AnimalState
{
private:
    int turnsLeft_;
public:
    WarnedState();

    AnimalState* update(Animal* animal);
    void move(Animal* animal, World* world);
};

#endif // WARNEDSTATE_H
