#ifndef WIND_H
#define WIND_H

class Wind
{
private:
    int xDir_;
    int yDir_;
public:
    Wind();
    void change();

    int getX() const {return xDir_;}
    int getY() const {return yDir_;}
};

#endif // WIND_H
