#include "animal.h"
#include "smellpool.h"
#include "player.h"

Animal::Animal(AnimatedModel* model_)
    : Kreatur ( model_),
      sightingX_(0),
      sightingY_(0),
      destinationX_(0),
      destinationY_(0)
{
    currentState_ = new CalmState();
}

void Animal::update(SmellPool* smellpool, World* world, Player* player)
{
    sightingX_ = 0;
    sightingY_ = 0;

    smellSense(smellpool);
    sightSense(player);

    AnimalState* state = currentState_->update(this);
    if(state != NULL){
        delete currentState_;
        currentState_ = state;
    }

    currentState_->move(this, world);
}

void Animal::circle(QQueue<int> &queue, int radius)
{
    int f = 1 - radius;
    int ddF_x = 0;
    int ddF_y = -2 * radius;
    int x = 0;
    int y = radius;

    queue.enqueue((position_.x()+14)/2);
    queue.enqueue((position_.z()+14)/2 + radius);

    queue.enqueue((position_.x()+14)/2);
    queue.enqueue((position_.z()+14)/2 - radius);

    queue.enqueue((position_.x()+14)/2 + radius);
    queue.enqueue((position_.z()+14)/2);

    queue.enqueue((position_.x()+14)/2 - radius);
    queue.enqueue((position_.z()+14)/2);

//    queue.enqueue(xPos_);
//    queue.enqueue(yPos_ + radius);

//    queue.enqueue(xPos_);
//    queue.enqueue(yPos_ - radius);

//    queue.enqueue(xPos_ + radius);
//    queue.enqueue(yPos_);

//    queue.enqueue(xPos_ - radius);
//    queue.enqueue(yPos_);

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

//        queue.enqueue(xPos_ + x);
//        queue.enqueue(yPos_ + y);

//        queue.enqueue(xPos_ - x);
//        queue.enqueue(yPos_ + y);

//        queue.enqueue(xPos_ + x);
//        queue.enqueue(yPos_ - y);

//        queue.enqueue(xPos_ - x);
//        queue.enqueue(yPos_ - y);

//        queue.enqueue(xPos_ + y);
//        queue.enqueue(yPos_ + x);

//        queue.enqueue(xPos_ - y);
//        queue.enqueue(yPos_ + x);

//        queue.enqueue(xPos_ + y);
//        queue.enqueue(yPos_ - x);

//        queue.enqueue(xPos_ - y);
//        queue.enqueue(yPos_ - x);

        queue.enqueue((position_.x()+14)/2 + x);
        queue.enqueue((position_.z()+14)/2 + y);

        queue.enqueue((position_.x()+14)/2 - x);
        queue.enqueue((position_.z()+14)/2 + y);

        queue.enqueue((position_.x()+14)/2 + x);
        queue.enqueue((position_.z()+14)/2 - y);

        queue.enqueue((position_.x()+14)/2 - x);
        queue.enqueue((position_.z()+14)/2 - y);

        queue.enqueue((position_.x()+14)/2 + y);
        queue.enqueue((position_.z()+14)/2 + x);

        queue.enqueue((position_.x()+14)/2 - y);
        queue.enqueue((position_.z()+14)/2 + x);

        queue.enqueue((position_.x()+14)/2 + y);
        queue.enqueue((position_.z()+14)/2 - x);

        queue.enqueue((position_.x()+14)/2 - y);
        queue.enqueue((position_.z()+14)/2 - x);

    }

}

void Animal::smellSense(SmellPool* smellpool)
{
    QQueue<int> sightings;
    for (int i = currentState_->getSmellRange(); i > 0; i--)
        circle(sightings, i);

    if(sightings.isEmpty())
        return;

    int xBuf, yBuf;
    for (int i = sightings.size()/2; i >= 0; i--){
        xBuf = sightings.dequeue();
        yBuf = sightings.dequeue();

        if (smellpool->isSmell(xBuf, yBuf)){
            sightingX_=(sightingX_+xBuf+1)/2;
            sightingY_=(sightingY_+yBuf+1)/2;
        }
    }
}

void Animal::sightSense(Player* player)
{
    QQueue<int> sightings;
    for (int i = currentState_->getSightRange(); i > 0; i--)
        circle(sightings, i);

    if(sightings.isEmpty())
        return;

    int xBuf, yBuf;
    for (int i = sightings.size()/2; i >= 0; i--){
        xBuf = sightings.dequeue();
        yBuf = sightings.dequeue();

        int playerPosX = (player->getPosition()->x()+14)/2;
        int playerPosY = (player->getPosition()->z()+14)/2;

        if (xBuf == playerPosX && yBuf == playerPosY){
            sightingX_=(sightingX_+xBuf*2+1)/3;
            sightingY_=(sightingY_+yBuf*2+1)/3;
            return;
        }
    }
}
