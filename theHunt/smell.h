#ifndef SMELL_H
#define SMELL_H

class Smell
{
private:
    int xPos_;
    int yPos_;
    int turnsLeft_;
    bool positiv_;
public:
    Smell();
    void init(int intensity, bool effect);
    void animate(int windX, int windY);
    bool inUse() const;
    int getX() const {return xPos_;}
    int getY() const {return yPos_;}
};

#endif // SMELL_H
