#ifndef PLAYER_H
#define PLAYER_H

#include "kreatur.h"

class World;

class Player : public Kreatur
{
public:
    Player(AnimatedModel* model_);
    void handleInput(int key, World* world);
};

#endif // PLAYER_H
