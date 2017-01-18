#ifndef ANIMALSTATE_H
#define ANIMALSTATE_H

class Animal;
class World;

class AnimalState
{
public:
    int getSmellRange() const {return smellRange_;}
    int getSightRange() const {return sightRange_;}

    AnimalState(){}
	virtual ~AnimalState(){}
    virtual AnimalState* update(Animal* animal) = 0;
    virtual void move(Animal* animal, World* world) = 0;

protected:
    int sightRange_;
    int smellRange_;    
};

#endif // ANIMALSTATE_H
