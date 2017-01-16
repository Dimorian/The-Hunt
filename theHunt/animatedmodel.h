#ifndef ANIMATEDMODEL_H
#define ANIMATEDMODEL_H

#include "drawable.h"
#include "trianglemesh.h"
#include "qlist.h"
#include "qstring.h"
#include "transformation.h"
#include "math.h"
#include "stdio.h"
class AnimatedModel : public Drawable
{
public:


	AnimatedModel(QString standPath, int standFrames);
	AnimatedModel(QString standPath, int standFrames,
							QString walkPath, int walkFrames    );

	AnimatedModel(QString standPath, int standFrames,
							QString walkPath, int walkFrames,
							QString runPath, int runFrames);


	  AnimatedModel(QString Path, QList<TriangleMesh*> *ListPointer1, QList<TriangleMesh*> *ListPointer2) ;
	  AnimatedModel(QString Path, QList<TriangleMesh*> *ListPointer1, QList<TriangleMesh*> *ListPointer2, QList<TriangleMesh*> *ListPointer3) ;
	  QList<TriangleMesh*>* getListPointer(int i);

	void toAnim(int i);
	void initLists();
	void nextFrame();

	void update(QVector3D *position, QVector2D *richtung);

	virtual void beforeTraverseChilds(SGObjectVisitor& visitor) override;
	virtual void afterTraverseChilds() override;

	inline void setScale(float sx, float sy, float sz);

private:
	void setPosition(float x, float y, float z);
	void fillList(QString path, int frames, QList<TriangleMesh*> * ListPointer);
	void init();
	float angle(QVector2D* v);

	Transformation* mTrafo;
	int iAktuell = 0;
	QVector3D *mScale = new QVector3D(1.0f,1.0f,1.0f);
	QList<TriangleMesh*> *mListPointer;
	QList<TriangleMesh*> *mAnim1;
	QList<TriangleMesh*> *mAnim2;
	QList<TriangleMesh*> *mAnim3;
	QList<TriangleMesh*> *mAnim4;
	QList<TriangleMesh*> *mAnim5;
};

inline void AnimatedModel::setScale(float sx, float sy, float sz){
  delete mScale;
  mScale = new QVector3D(sx,sy,sz);
}

#endif // ANIMATEDMODEL_H
