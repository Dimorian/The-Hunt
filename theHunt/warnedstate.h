#ifndef WARNEDSTATE_H
#define WARNEDSTATE_H

#include "animalstate.h"

class Animal;

class WarnedState : public AnimalState
{
public:
    WarnedState();

    void update(Animal* animal);
    void move(Animal* animal);
};

#endif // WARNEDSTATE_H
