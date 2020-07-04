#ifndef _POSITION_H_
#define _POSITION_H_

#include <iostream>
#include "pub.h"

class Position 
{
    public:
    Position();
    Position(Pos ix, Pos iy, Pos iz, Direct id);
    bool operator==(const Position &pos) const;
    void up(int n);
    void down(int n);
    void forward(int n);
    void left();
    void right();
    void round();
    private:
    Pos x,y,z;
    Direct d;
};

#endif