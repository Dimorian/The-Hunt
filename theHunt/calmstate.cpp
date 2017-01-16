#include "calmstate.h"
#include <time.h>
#include <stdlib.h>
#include <vector>

#include "animal.h"

CalmState::CalmState()
{
    sightRange_ = 4;
    smellRange_ = 3;
}

void CalmState::update(Animal* animal)
{
    animal->sightingX_ = 0;
    animal->sightingY_ = 0;

    bool change = false;
    change = animal->smellSense();
    if(change)
        animal->sightSense();
    else
        change = animal->sightSense();

    if(change)
        //animal->currentState_ = &Animal::warned;  //undefined reference error

    animal->move();
}

void CalmState::move(Animal* animal)
{
    srand(time(NULL));
    int xPos = animal->xPos_;
    int yPos = animal->yPos_;
    int xBuf, yBuf;

    std::vector<int> changes;

    for (int x = -1; x <= 1; x++)
        for (int y = -1; y <= 1; y++){
            changes.push_back(x);
            changes.push_back(y);
        }

    int size = 18;
    int randIterator;
    do{
        randIterator = (rand()%(size/2))*2;
        size -= 2;
        xBuf = changes[randIterator];
        yBuf = changes[randIterator+1];
        changes.erase (changes.begin()+randIterator, changes.begin()+randIterator+1);
    }while(false);   //TODO: Abfrage der World über Vermittlerklasse in animal, ob Feld begehbar

    //TODO: Zuweisung auf animal Position
}
