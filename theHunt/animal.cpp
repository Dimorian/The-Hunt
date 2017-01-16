#include "animal.h"

Animal::Animal()
    : sightingX_(0),
      sightingY_(0),
      destinationX_(0),
      destinationY_(0)
{
}

void Animal::update()
{
    currentState_->update(this);
}

void Animal::move()
{
    currentState_->move(this);
}

void Animal::circle(std::queue<int> &queue, int radius)
{
    int f = 1 - radius;
    int ddF_x = 0;
    int ddF_y = -2 * radius;
    int x = 0;
    int y = radius;

    queue.push(xPos_);
    queue.push(yPos_ + radius);

    queue.push(xPos_);
    queue.push(yPos_ - radius);

    queue.push(xPos_ + radius);
    queue.push(yPos_);

    queue.push(xPos_ - radius);
    queue.push(yPos_);

    while(x < y)
    {
        if(f >= 0)
        {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x + 1;

        queue.push(xPos_ + x);
        queue.push(yPos_ + y);

        queue.push(xPos_ - x);
        queue.push(yPos_ + y);

        queue.push(xPos_ + x);
        queue.push(yPos_ - y);

        queue.push(xPos_ - x);
        queue.push(yPos_ - y);

        queue.push(xPos_ + y);
        queue.push(yPos_ + x);

        queue.push(xPos_ - y);
        queue.push(yPos_ + x);

        queue.push(xPos_ + y);
        queue.push(yPos_ - x);

        queue.push(xPos_ - y);
        queue.push(yPos_ - x);
    }
}

bool Animal::smellSense()
{
    std::queue<int> sightings;
    for (int i = currentState_->getSmellRange(); i > 0; i--)
        circle(sightings, i);

    //Ausstieg wenn keine Sichtung
    if(sightings.size()==0)
        return false;

    int xBuf, yBuf;
    for (int i = sightings.size()/2; i >= 0; i--){
        xBuf = sightings.front();
        sightings.pop();
        yBuf = sightings.front();
        sightings.pop();

        //TODO: wenn Smellpool-Test true
        /*
        if (){
            sightingX_=(sightingX_+xBuf+1)/2;
            sightingY_=(sightingY_+yBuf+1)/2;
        }*/
    }
    return true;
}

bool Animal::sightSense()
{
    std::queue<int> sightings;
    for (int i = currentState_->getSightRange(); i > 0; i--)
        circle(sightings, i);

    //Ausstieg wenn keine Sichtung
    if(sightings.size()==0)
        return false;

    int xBuf, yBuf;
    for (int i = sightings.size()/2; i >= 0; i--){
        xBuf = sightings.front();
        sightings.pop();
        yBuf = sightings.front();
        sightings.pop();

        //TODO: wenn Sicht-Test true
        /*
        if (){
            sightingX_=(sightingX_+xBuf*2+1)/3;
            sightingY_=(sightingY_+yBuf*2+1)/3;
        }*/
    }
    return true;
}
