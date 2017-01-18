#ifndef WIND_H
#define WIND_H


#include "qlist.h"
#include "drawable.h"
class Wind
{
private:
    int xDir_;
    int yDir_;
	QList <Drawable*> *drawables_;
public:
	Wind(QList <Drawable*> *drawables);
    void change();

    int getX() const {return xDir_;}
    int getY() const {return yDir_;}
};

#endif // WIND_H
