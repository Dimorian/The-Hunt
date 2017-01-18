#include "player.h"

Player::Player(AnimatedModel* model_)
    : Kreatur ( model_)
{

}

void Player::handleInput(int key)
{
    QVector2D* buf = new QVector2D();
    if (key == 'w'){
        position_.setZ(position_.z()-2.0f);
        buf->setX(0.0f);
        buf->setY(-1.0f);
        setRichtung(buf);
    }else if(key == 'a'){
        position_.setX(position_.x()-2.0f);
        buf->setX(-1.0f);
        buf->setY(0.0f);
        setRichtung(buf);
    }else if(key == 's'){
        position_.setZ(position_.z()+2.0f);
        buf->setX(0.0f);
        buf->setY(1.0f);
        setRichtung(buf);
    }else if(key == 'd'){
        position_.setX(position_.x()+2.0f);
        buf->setX(1.0f);
        buf->setY(0.0f);
        setRichtung(buf);
    }
}
