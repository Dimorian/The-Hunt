#include "controller.h"
#include "inputobserver.h"

Controller::Controller(Camera* cam, Animal* animal, SmellPool* smellpool, World* world)
	:cam_(cam), animal_(animal), smellpool_(smellpool), world_(world)
{
	addMeNow();
}


void Controller::doIt(){


	if ( InputObserver::isKeyPressed('w') )
	{
//		spieler_->handleInput('w');
	}
	else
	{
//		spieler_->handleInput(' ');
	}


	if ( InputObserver::isKeyPressed('a') )
	{
//		Spieler_->handleInput('a');

	}
	if ( InputObserver::isKeyPressed('d') )
	{
//		Spieler_->handleInput('d');

	}

//	animal_->update();

}
