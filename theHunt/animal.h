#ifndef ANIMAL_H
#define ANIMAL_H

#include <queue>
#include "animalstate.h"
#include "calmstate.h"
#include "warnedstate.h"
//TODO: include Verwaltungsklasse für Sinnetests

class Animal
{   
friend class CalmState;
friend class WarnedState;

private:
    //andere Positionierung der States bei mehr Tieren, die die States nutzen
    static CalmState calm;
    static WarnedState warned;

    int xPos_;
    int yPos_;
    int xDir_;
    int yDir_;
    int sightingX_;
    int sightingY_;
    int destinationX_;
    int destinationY_;
    AnimalState* currentState_;

    void circle(std::queue<int>& queue, int radius);
    bool sightSense();
    bool smellSense();

public:
    Animal();
    void update();
    void move();
};

#endif // ANIMAL_H
