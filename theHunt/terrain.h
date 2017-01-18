#ifndef TERRAIN_H
#define TERRAIN_H

class Terrain
{
private:
    bool sichtbar_;
    bool begehbar_;

public:
    Terrain(bool sichtbar, bool begehbar)
        : sichtbar_(sichtbar),
          begehbar_(begehbar)
    {}

    bool getSichtbar() const {return sichtbar_;}
    bool getBegehbar() const {return begehbar_;}
};

#endif // TERRAIN_H
