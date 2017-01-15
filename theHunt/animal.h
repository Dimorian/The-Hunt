#ifndef ANIMAL_H
#define ANIMAL_H

#include "animalstate.h"

class Animal
{
private:
    int xPos_;
    int yPos_;
    int xDir_;
    int yDir_;
    AnimalState* currentState;
public:
    Animal();
    void animate();

    //TODO: Funktionen zur Abfrage der Sinne
};

#endif // ANIMAL_H
