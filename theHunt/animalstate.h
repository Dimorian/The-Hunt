#ifndef ANIMALSTATE_H
#define ANIMALSTATE_H

class Animal;

class AnimalState
{
protected:
    int sightRange_;
    int smellRange_;
public:
    virtual void animate(Animal& animal) = 0;
};

#endif // ANIMALSTATE_H
