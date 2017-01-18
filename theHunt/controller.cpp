#include "controller.h"
#include "inputobserver.h"

Controller::Controller(Camera* cam, Animal* animal, SmellPool* smellpool, World* world, Player* player, Wind* wind)
    :wait_(0), cam_(cam), animal_(animal), smellpool_(smellpool), world_(world), player_(player), wind_(wind)
{
	addMeNow();
}


void Controller::doIt(){

    if((InputObserver::isKeyPressed('w') || InputObserver::isKeyPressed('a')
            || InputObserver::isKeyPressed('s') || InputObserver::isKeyPressed('d')) && wait_ == 0)
    {
        if ( InputObserver::isKeyPressed('w') )
        {
            player_->handleInput('w', world_);
        }
        else if ( InputObserver::isKeyPressed('a') )
        {
            player_->handleInput('a', world_);
        }
        else if ( InputObserver::isKeyPressed('d') )
        {
            player_->handleInput('d', world_);
        }
        else if ( InputObserver::isKeyPressed('s') )
        {
            player_->handleInput('s', world_);
        }

        smellpool_->animate(wind_->getX(), wind_->getY());

        //neue Geruchspartikel erstellen
        smellpool_->create(4, true, (player_->getPosition()->x()+14)/2, (player_->getPosition()->z()+14)/2);
        smellpool_->create(4, true, (player_->getPosition()->x()+14)/2+1, (player_->getPosition()->z()+14)/2);
        smellpool_->create(4, true, (player_->getPosition()->x()+14)/2-1, (player_->getPosition()->z()+14)/2);
        smellpool_->create(4, true, (player_->getPosition()->x()+14)/2, (player_->getPosition()->z()+14)/2+1);
        smellpool_->create(4, true, (player_->getPosition()->x()+14)/2, (player_->getPosition()->z()+14)/2-1);

        animal_->update(smellpool_, world_, player_);
        wind_->change();

        wait_ = 300;
    }

    //...aller Stuff der jeden Zyklus durchgeführt wird...
    //animal_->update();
    player_->update();

    if(wait_ > 0)
        wait_--;
}
