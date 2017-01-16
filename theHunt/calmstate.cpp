#include "calmstate.h"
#include <time.h>
#include <stdlib.h>
#include <QVector>

#include "animal.h"
#include "warnedstate.h"

CalmState::CalmState()
{
    sightRange_ = 4;
    smellRange_ = 3;
}

AnimalState* CalmState::update(Animal* animal)
{
    animal->sightingX_ = 0;
    animal->sightingY_ = 0;

    animal->smellSense();
    animal->sightSense();

    if(animal->sightingX_ != 0 || animal->sightingY_ != 0)  //nicht optimal
        return new WarnedState;

    return NULL;
}

void CalmState::move(Animal* animal)
{
    srand(time(NULL));
    int xPos = animal->xPos_;
    int yPos = animal->yPos_;
    int xBuf, yBuf;

    QVector<int> changes;

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
    animal->xPos_ += xBuf;
    animal->yPos_ += yBuf;
}
