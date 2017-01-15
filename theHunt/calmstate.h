#ifndef CALMSTATE_H
#define CALMSTATE_H

#include "animalstate.h"

class CalmState : public AnimalState
{
public:
    CalmState();
    void animate(Animal& animal);
};

#endif // CALMSTATE_H
