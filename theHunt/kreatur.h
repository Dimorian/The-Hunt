#ifndef KREATUR_H
#define KREATUR_H

#include "animatedmodel.h"

class Kreatur
{
public:
	Kreatur(AnimatedModel* model_);

	void update();
	void move(float faktor);
	void rotate();
	void PrintRotundPos();

	inline void setRichtung(QVector2D* richtung);
	inline void setfDrehung(float drehung);
	inline AnimatedModel* getAnimatedModel();
	inline QVector3D* getPosition();
	inline QVector2D* getRichtung();
	inline void scale(float s);
	inline void setPosition(QVector3D* pos);

protected:
	AnimatedModel* model_;
	QVector3D position_;
	QVector2D richtung_;
	float fDrehung_ = 0.0;

};
inline void Kreatur::setfDrehung(float Drehung){
	fDrehung_ = Drehung;
}
inline void Kreatur::setRichtung(QVector2D* v){


	richtung_.setX(v->x());
	richtung_.setY(v->y());
	richtung_.normalize();
}
inline AnimatedModel* Kreatur::getAnimatedModel()
{
	return model_;
}
inline QVector3D* Kreatur::getPosition(){
	return &position_;
}
inline QVector2D* Kreatur::getRichtung(){
	return &richtung_;
}
inline void Kreatur::scale(float s){
  model_->setScale(s,s,s);
}
inline void Kreatur::setPosition(QVector3D *pos){
	position_ = *pos;
}

#endif // KREATUR_H
