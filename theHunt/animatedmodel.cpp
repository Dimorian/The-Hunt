#include "animatedmodel.h"


AnimatedModel::AnimatedModel(QString standPath, int standFrames)
						: Drawable(new TriangleMesh(standPath+QString("01.obj") ))
{
	mListPointer = mAnim1;

	initLists();

	fillList(standPath, standFrames, mAnim1);
	init();
}

AnimatedModel::AnimatedModel(QString standPath, int standFrames,
							 QString walkPath, int walkFrames    )
						: Drawable(new TriangleMesh(standPath+QString("01.obj") ))
{
	mListPointer = mAnim1;

   initLists();

	fillList(standPath, standFrames, mAnim1);
	fillList(walkPath, walkFrames, mAnim2);
	init();
}

AnimatedModel::AnimatedModel(QString standPath, int standFrames,
							 QString walkPath, int walkFrames , QString runPath, int runFrames   )
						: Drawable(new TriangleMesh(standPath+QString("01.obj") ))
{
	mListPointer = mAnim1;

	initLists();

	fillList(standPath, standFrames, mAnim1);
	fillList(walkPath, walkFrames, mAnim2);
	fillList(runPath, runFrames, mAnim3);
	init();
}

AnimatedModel::AnimatedModel(QString Path, QList<TriangleMesh*> *ListPointer1, QList<TriangleMesh*> *ListPointer2)
						: Drawable(new TriangleMesh( Path+QString("01.obj")))
{
  mAnim1=ListPointer1;
  mAnim2=ListPointer2;

  mListPointer = mAnim1;
  init();

}

AnimatedModel::AnimatedModel(QString Path, QList<TriangleMesh*> *ListPointer1, QList<TriangleMesh*> *ListPointer2
							 , QList<TriangleMesh*> *ListPointer3): Drawable(new TriangleMesh( Path+QString("01.obj")))
{
  mAnim1=ListPointer1;
  mAnim2=ListPointer2;
  mAnim3=ListPointer3;
  mListPointer = mAnim1;
  init();
}

void AnimatedModel::initLists(){

	mAnim1 = new QList<TriangleMesh*>;
	mAnim2 = new QList<TriangleMesh*>;
	mAnim3 = new QList<TriangleMesh*>;
	mAnim4 = new QList<TriangleMesh*>;
	mAnim5 = new QList<TriangleMesh*>;

}

QList<TriangleMesh*>* AnimatedModel::getListPointer(int i){

  switch (i) {
	case 1:
	  return mAnim1;
	  break;
	case 2:
	  return mAnim2;
	  break;
	case 3:
	  return mAnim3;
	  break;
	case 4:
	  return mAnim4;
	  break;
	case 5:
	  return mAnim5;
	  break;
	default:
	  return nullptr;
	  break;
	}
}

void AnimatedModel::fillList(QString path, int frames, QList<TriangleMesh*> * ListPointer){


	switch (frames) {
	case 99:
		ListPointer->append( new TriangleMesh( path+QString("99.obj")  ) );
	case 98:
		ListPointer->append( new TriangleMesh( path+QString("98.obj")  ) );
	case 97:
		ListPointer->append( new TriangleMesh( path+QString("97.obj")  ) );
	case 96:
		ListPointer->append( new TriangleMesh( path+QString("96.obj")  ) );
	case 95:
		ListPointer->append( new TriangleMesh( path+QString("95.obj")  ) );
	case 94:
		ListPointer->append( new TriangleMesh( path+QString("94.obj")  ) );
	case 93:
		ListPointer->append( new TriangleMesh( path+QString("93.obj")  ) );
	case 92:
		ListPointer->append( new TriangleMesh( path+QString("92.obj")  ) );
	case 91:
		ListPointer->append( new TriangleMesh( path+QString("91.obj")  ) );
	case 90:
		ListPointer->append( new TriangleMesh( path+QString("90.obj")  ) );
	case 89:
		ListPointer->append( new TriangleMesh( path+QString("89.obj")  ) );
	case 88:
		ListPointer->append( new TriangleMesh( path+QString("88.obj")  ) );
	case 87:
		ListPointer->append( new TriangleMesh( path+QString("87.obj")  ) );
	case 86:
		ListPointer->append( new TriangleMesh( path+QString("86.obj")  ) );
	case 85:
		ListPointer->append( new TriangleMesh( path+QString("85.obj")  ) );
	case 84:
		ListPointer->append( new TriangleMesh( path+QString("84.obj")  ) );
	case 83:
		ListPointer->append( new TriangleMesh( path+QString("83.obj")  ) );
	case 82:
		ListPointer->append( new TriangleMesh( path+QString("82.obj")  ) );
	case 81:
		ListPointer->append( new TriangleMesh( path+QString("81.obj")  ) );
	case 80:
		ListPointer->append( new TriangleMesh( path+QString("80.obj")  ) );
	case 79:
		ListPointer->append( new TriangleMesh( path+QString("79.obj")  ) );
	case 78:
		ListPointer->append( new TriangleMesh( path+QString("78.obj")  ) );
	case 77:
		ListPointer->append( new TriangleMesh( path+QString("77.obj")  ) );
	case 76:
		ListPointer->append( new TriangleMesh( path+QString("76.obj")  ) );
	case 75:
		ListPointer->append( new TriangleMesh( path+QString("75.obj")  ) );
	case 74:
		ListPointer->append( new TriangleMesh( path+QString("74.obj")  ) );
	case 73:
		ListPointer->append( new TriangleMesh( path+QString("73.obj")  ) );
	case 72:
		ListPointer->append( new TriangleMesh( path+QString("72.obj")  ) );
	case 71:
		ListPointer->append( new TriangleMesh( path+QString("71.obj")  ) );
	case 70:
		ListPointer->append( new TriangleMesh( path+QString("70.obj")  ) );
	case 69:
		ListPointer->append( new TriangleMesh( path+QString("69.obj")  ) );
	case 68:
		ListPointer->append( new TriangleMesh( path+QString("68.obj")  ) );
	case 67:
		ListPointer->append( new TriangleMesh( path+QString("67.obj")  ) );
	case 66:
		ListPointer->append( new TriangleMesh( path+QString("66.obj")  ) );
	case 65:
		ListPointer->append( new TriangleMesh( path+QString("65.obj")  ) );
	case 64:
		ListPointer->append( new TriangleMesh( path+QString("64.obj")  ) );
	case 63:
		ListPointer->append( new TriangleMesh( path+QString("63.obj")  ) );
	case 62:
		ListPointer->append( new TriangleMesh( path+QString("62.obj")  ) );
	case 61:
		ListPointer->append( new TriangleMesh( path+QString("61.obj")  ) );
	case 60:
		ListPointer->append( new TriangleMesh( path+QString("60.obj")  ) );
	case 59:
		ListPointer->append( new TriangleMesh( path+QString("59.obj")  ) );
	case 58:
		ListPointer->append( new TriangleMesh( path+QString("58.obj")  ) );
	case 57:
		ListPointer->append( new TriangleMesh( path+QString("57.obj")  ) );
	case 56:
		ListPointer->append( new TriangleMesh( path+QString("56.obj")  ) );
	case 55:
		ListPointer->append( new TriangleMesh( path+QString("55.obj")  ) );
	case 54:
		ListPointer->append( new TriangleMesh( path+QString("54.obj")  ) );
	case 53:
		ListPointer->append( new TriangleMesh( path+QString("53.obj")  ) );
	case 52:
		ListPointer->append( new TriangleMesh( path+QString("52.obj")  ) );
	case 51:
		ListPointer->append( new TriangleMesh( path+QString("51.obj")  ) );
	case 50:
		ListPointer->append( new TriangleMesh( path+QString("50.obj")  ) );
	case 49:
		ListPointer->append( new TriangleMesh( path+QString("49.obj")  ) );
	case 48:
		ListPointer->append( new TriangleMesh( path+QString("48.obj")  ) );
	case 47:
		ListPointer->append( new TriangleMesh( path+QString("47.obj")  ) );
	case 46:
		ListPointer->append( new TriangleMesh( path+QString("46.obj")  ) );
	case 45:
		ListPointer->append( new TriangleMesh( path+QString("45.obj")  ) );
	case 44:
		ListPointer->append( new TriangleMesh( path+QString("44.obj")  ) );
	case 43:
		ListPointer->append( new TriangleMesh( path+QString("43.obj")  ) );
	case 42:
		ListPointer->append( new TriangleMesh( path+QString("42.obj")  ) );
	case 41:
		ListPointer->append( new TriangleMesh( path+QString("41.obj")  ) );
	case 40:
		ListPointer->append( new TriangleMesh( path+QString("40.obj")  ) );
	case 39:
		ListPointer->append( new TriangleMesh( path+QString("39.obj")  ) );
	case 38:
		ListPointer->append( new TriangleMesh( path+QString("38.obj")  ) );
	case 37:
		ListPointer->append( new TriangleMesh( path+QString("37.obj")  ) );
	case 36:
		ListPointer->append( new TriangleMesh( path+QString("36.obj")  ) );
	case 35:
		ListPointer->append( new TriangleMesh( path+QString("35.obj")  ) );
	case 34:
		ListPointer->append( new TriangleMesh( path+QString("34.obj")  ) );
	case 33:
		ListPointer->append( new TriangleMesh( path+QString("33.obj")  ) );
	case 32:
		ListPointer->append( new TriangleMesh( path+QString("32.obj")  ) );
	case 31:
		ListPointer->append( new TriangleMesh( path+QString("31.obj")  ) );
	case 30:
		ListPointer->append( new TriangleMesh( path+QString("30.obj")  ) );
	case 29:
		ListPointer->append( new TriangleMesh( path+QString("29.obj")  ) );
	case 28:
		ListPointer->append( new TriangleMesh( path+QString("28.obj")  ) );
	case 27:
		ListPointer->append( new TriangleMesh( path+QString("27.obj")  ) );
	case 26:
		ListPointer->append( new TriangleMesh( path+QString("26.obj")  ) );
	case 25:
		ListPointer->append( new TriangleMesh( path+QString("25.obj")  ) );
	case 24:
		ListPointer->append( new TriangleMesh( path+QString("24.obj")  ) );
	case 23:
		ListPointer->append( new TriangleMesh( path+QString("23.obj")  ) );
	case 22:
		ListPointer->append( new TriangleMesh( path+QString("22.obj")  ) );
	case 21:
		ListPointer->append( new TriangleMesh( path+QString("21.obj")  ) );
	case 20:
		ListPointer->append( new TriangleMesh( path+QString("20.obj")  ) );
	case 19:
		ListPointer->append( new TriangleMesh( path+QString("19.obj")  ) );
	case 18:
		ListPointer->append( new TriangleMesh( path+QString("18.obj")  ) );
	case 17:
		ListPointer->append( new TriangleMesh( path+QString("17.obj")  ) );
	case 16:
		ListPointer->append( new TriangleMesh( path+QString("16.obj")  ) );
	case 15:
		ListPointer->append( new TriangleMesh( path+QString("15.obj")  ) );
	case 14:
		ListPointer->append( new TriangleMesh( path+QString("14.obj")  ) );
	case 13:
		ListPointer->append( new TriangleMesh( path+QString("13.obj")  ) );
	case 12:
		ListPointer->append( new TriangleMesh( path+QString("12.obj")  ) );
	case 11:
		ListPointer->append( new TriangleMesh( path+QString("11.obj")  ) );
	case 10:
		ListPointer->append( new TriangleMesh( path+QString("10.obj")  ) );
	case 9:
		ListPointer->append( new TriangleMesh( path+QString("09.obj")  ) );
	case 8:
		ListPointer->append( new TriangleMesh( path+QString("08.obj")  ) );
	case 7:
		ListPointer->append( new TriangleMesh( path+QString("07.obj")  ) );
	case 6:
		ListPointer->append( new TriangleMesh( path+QString("06.obj")  ) );
	case 5:
		ListPointer->append( new TriangleMesh( path+QString("05.obj")  ) );
	case 4:
		ListPointer->append( new TriangleMesh( path+QString("04.obj")  ) );
	case 3:
		ListPointer->append( new TriangleMesh( path+QString("03.obj")  ) );
	case 2:
		ListPointer->append( new TriangleMesh( path+QString("02.obj")  ) );
	case 1:
		ListPointer->append( new TriangleMesh( path+QString("01.obj")  ) );
	}

}

void AnimatedModel::toAnim(int i){

	switch (i) {
	  case 1:

		if(!mAnim1->empty())
		mListPointer= mAnim1;
		break;
	  case 2:

		if(!mAnim2->empty())
		mListPointer= mAnim2;
		break;
	  case 3:

		if(!mAnim3->empty())
		mListPointer= mAnim3;
		break;
	  case 4:

		if(!mAnim4->empty())
		mListPointer= mAnim4;
		break;
	  case 5:

		if(!mAnim5->empty())
		mListPointer= mAnim5;
		break;
	  }

	iAktuell = mListPointer->length()-1;
}

void AnimatedModel::nextFrame(){
	setGeometry(mListPointer->at(iAktuell));
	iAktuell--;
	if(iAktuell<=0)
		iAktuell=mListPointer->length()-1;
}

void AnimatedModel::update(QVector3D *position, QVector2D *richtung){

	//printf("AnimatedModel::update angle: %f\n", angle(richtung));

	//Erst die Transformation zurücksetzen
	mTrafo->resetTrafo();

	//Dann rotieren
	setPosition(position->x(), position->y(), position->z());
	mTrafo->scale(*mScale);
	mTrafo->rotate(angle(richtung),0.0,1.0,0.0);
	mTrafo->rotate(90.0, 0.0, 1.0, 0.0);
	//und dann verschieben

}

void AnimatedModel::setPosition(float x, float y, float z){
	mTrafo->translate(x,y,z);
}

void AnimatedModel::init(){
	mTrafo = new Transformation;
}

float AnimatedModel::angle(QVector2D* v){
	if (v->y()< 0)
	   return (acosf( v->x() / sqrt( (v->x() * v->x()) + (v->y() * v->y()) )  )* (180/3.141592653));
	   return -(acosf( v->x() / sqrt( (v->x() * v->x()) + (v->y() * v->y()) )  ))* (180/3.141592653);
}

void AnimatedModel::beforeTraverseChilds(SGObjectVisitor& visitor)
{
	mTrafo->activate();
	Drawable::beforeTraverseChilds(visitor);
}

void AnimatedModel::afterTraverseChilds()
{
	mTrafo->deActivate();
}
