#ifndef SMELLPOOL_H
#define SMELLPOOL_H

#include "smell.h"

class SmellPool
{
private:
    static const int POOLSIZE = 50;
    Smell smelltokens_[POOLSIZE];
public:
    SmellPool();

    void animate(int windX, int windY);
    void create(int intensity, bool effect);
};

#endif // SMELLPOOL_H
