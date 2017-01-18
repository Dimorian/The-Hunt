#include "controller.h"
#include "inputobserver.h"

Controller::Controller(Camera* cam, Animal* animal, SmellPool* smellpool, World* world, Player* player, Wind* wind)
    :cam_(cam), animal_(animal), smellpool_(smellpool), world_(world), player_(player), wind_(wind)
{
	addMeNow();
}


void Controller::doIt(){

    if(InputObserver::isKeyPressed('w') || InputObserver::isKeyPressed('a')
            || InputObserver::isKeyPressed('s') || InputObserver::isKeyPressed('d'))
    {
        if ( InputObserver::isKeyPressed('w') )
        {
            player_->handleInput('w');
        }
        else if ( InputObserver::isKeyPressed('a') )
        {
            player_->handleInput('a');
        }
        else if ( InputObserver::isKeyPressed('d') )
        {
            player_->handleInput('d');
        }
        else if ( InputObserver::isKeyPressed('s') )
        {
            player_->handleInput('s');
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
    }

    //...aller Stuff der jeden Zyklus durchgeführt wird...
    //animal_->update();
    player_->update();
}
