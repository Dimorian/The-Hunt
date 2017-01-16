#ifndef ANIMAL_H
#define ANIMAL_H
#include "kreatur.h"
#include <QQueue>
#include "animalstate.h"
#include "calmstate.h"
#include "warnedstate.h"
//TODO: include Verwaltungsklasse für Sinnetests

class Animal : public Kreatur
{   
friend class CalmState;
friend class WarnedState;

private:
//    int xPos_;
//    int yPos_;
//    int xDir_;
//    int yDir_;

    int sightingX_;
    int sightingY_;
    int destinationX_;
    int destinationY_;
    AnimalState* currentState_;

    void circle(QQueue<int>& queue, int radius);
    void sightSense();
    void smellSense();

public:
	Animal(AnimatedModel* model_);
    void update();
};

#endif // ANIMAL_H
