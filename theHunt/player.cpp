#include "player.h"
#include "world.h"


Player::Player(AnimatedModel* model_)
    : Kreatur ( model_)
{
}

void Player::handleInput(int key, World* world)
{
    int xPos = (position_.x()+14)/2;
    int yPos = (position_.z()+14)/2;
    QVector2D* buf = new QVector2D();
    if (key == 'w' && world->getTile(xPos+1, yPos)->getBegehbar()){
        position_.setX(position_.x()+2.0f);
        buf->setX(0.0f);
        buf->setY(-1.0f);
        setRichtung(buf);
    }else if(key == 'a' && world->getTile(xPos, yPos-1)->getBegehbar()){
        position_.setZ(position_.z()-2.0f);
        buf->setX(-1.0f);
        buf->setY(0.0f);
        setRichtung(buf);
    }else if(key == 's' && world->getTile(xPos-1, yPos)->getBegehbar()){
        position_.setX(position_.x()-2.0f);
        buf->setX(0.0f);
        buf->setY(1.0f);
        setRichtung(buf);
    }else if(key == 'd' && world->getTile(xPos, yPos+1)->getBegehbar()){
        position_.setZ(position_.z()+2.0f);
        buf->setX(1.0f);
        buf->setY(0.0f);
        setRichtung(buf);
    }
}
