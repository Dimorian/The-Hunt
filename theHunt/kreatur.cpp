#include "kreatur.h"

Kreatur::Kreatur(AnimatedModel* Model)
{
	model_ = Model;

	position_.setX(0.0);
	position_.setY(0.0);
	position_.setZ(0.0);

	richtung_.setX(1.0);
	richtung_.setY(0.0);

}
void Kreatur::update(){

	model_->update( &position_, &richtung_);

}

void Kreatur::move(float faktor){
	position_.setX(  (position_.x()+ (richtung_.x() * faktor)  )  );
	position_.setZ(  (position_.z()+ (richtung_.y() * faktor)  )  );
}

void Kreatur::rotate(){
	richtung_.setX(  cos(fDrehung_)*richtung_.x() + (-sin(fDrehung_)) * richtung_.y() );
	richtung_.setY(  sin(fDrehung_)*richtung_.x() + (cos(fDrehung_)) * richtung_.y()  );
	richtung_.normalize();
}
void Kreatur::PrintRotundPos(){



	printf("Kreatur:: PrintfRotundPos\n");
	printf("Position: \t%f\t%f\t%f \n", position_.x(), position_.y(),position_.z() );
	printf("Richtung: \t%f\t%f \n", richtung_.x(), richtung_.y() );


}
