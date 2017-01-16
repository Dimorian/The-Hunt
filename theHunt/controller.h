#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "idleobserver.h"
#include "animal.h"
#include "smellpool.h"
#include "camera.h"
#include "World.h"
class Controller : public IdleObserver
{
public:

	//ToDo: Konstruktor um Spielerptr erweitern, sobald vorhanden
	Controller(Camera* cam, Animal* animal, SmellPool* smellpool, World* world);

	void doIt() override;
private:

	Camera* cam_;
	Animal* animal_;
	SmellPool* smellpool_;
	World* world_;

};

#endif // CONTROLLER_H