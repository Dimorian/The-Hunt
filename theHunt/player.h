#ifndef PLAYER_H
#define PLAYER_H

#include "kreatur.h"

class Player : public Kreatur
{
public:
    Player(AnimatedModel* model_);
    void handleInput(int key);
};

#endif // PLAYER_H
