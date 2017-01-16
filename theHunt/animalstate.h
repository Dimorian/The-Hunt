#ifndef ANIMALSTATE_H
#define ANIMALSTATE_H

class Animal;

class AnimalState
{
public:
    int getSmellRange() {return smellRange_;}
    int getSightRange() {return sightRange_;}

    AnimalState(){}
    virtual void update(Animal* animal) = 0;
    virtual void move(Animal* animal) = 0;

protected:
    int sightRange_;
    int smellRange_;    
};

#endif // ANIMALSTATE_H
