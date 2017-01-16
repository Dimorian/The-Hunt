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
    AnimalState* state = currentState_->update(this);

    if(state != NULL){
        delete currentState_;
        currentState_ = state;
    }

    currentState_->move(this);
}

void Animal::circle(QQueue<int> &queue, int radius)
{
    int f = 1 - radius;
    int ddF_x = 0;
    int ddF_y = -2 * radius;
    int x = 0;
    int y = radius;

    queue.enqueue(xPos_);
    queue.enqueue(yPos_ + radius);

    queue.enqueue(xPos_);
    queue.enqueue(yPos_ - radius);

    queue.enqueue(xPos_ + radius);
    queue.enqueue(yPos_);

    queue.enqueue(xPos_ - radius);
    queue.enqueue(yPos_);

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

        queue.enqueue(xPos_ + x);
        queue.enqueue(yPos_ + y);

        queue.enqueue(xPos_ - x);
        queue.enqueue(yPos_ + y);

        queue.enqueue(xPos_ + x);
        queue.enqueue(yPos_ - y);

        queue.enqueue(xPos_ - x);
        queue.enqueue(yPos_ - y);

        queue.enqueue(xPos_ + y);
        queue.enqueue(yPos_ + x);

        queue.enqueue(xPos_ - y);
        queue.enqueue(yPos_ + x);

        queue.enqueue(xPos_ + y);
        queue.enqueue(yPos_ - x);

        queue.enqueue(xPos_ - y);
        queue.enqueue(yPos_ - x);
    }
}

void Animal::smellSense()
{
    QQueue<int> sightings;
    for (int i = currentState_->getSmellRange(); i > 0; i--)
        circle(sightings, i);

    int xBuf, yBuf;
    for (int i = sightings.size()/2; i >= 0; i--){
        xBuf = sightings.front();
        sightings.dequeue();
        yBuf = sightings.front();
        sightings.dequeue();

        //TODO: wenn Smellpool-Test true
        /*
        if (){
            sightingX_=(sightingX_+xBuf+1)/2;
            sightingY_=(sightingY_+yBuf+1)/2;
        }*/
    }
}

void Animal::sightSense()
{
    QQueue<int> sightings;
    for (int i = currentState_->getSightRange(); i > 0; i--)
        circle(sightings, i);

    int xBuf, yBuf;
    for (int i = sightings.size()/2; i >= 0; i--){
        xBuf = sightings.front();
        sightings.dequeue();
        yBuf = sightings.front();
        sightings.dequeue();

        //TODO: wenn Sicht-Test true
        /*
        if (){
            sightingX_=(sightingX_+xBuf*2+1)/3;
            sightingY_=(sightingY_+yBuf*2+1)/3;
        }*/
    }
}
