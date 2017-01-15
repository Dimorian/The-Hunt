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
};

#endif // SMELL_H
