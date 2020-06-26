#ifndef _POSITION_H_
#define _POSITION_H_

#include <iostream>
#include "pub.h"

class Position 
{
    public:
    Position():x(0),y(0),z(0),d(N){}
    Position(Pos ix, Pos iy, Pos iz, Direct id):x(ix),y(iy),z(iz),d(id){}
    bool operator==(const Position &pos) const;
    bool operator!=(const Position &pos) const;
    void up(int n);
    void down(int n);
    void forward(int n);
    void left();
    void right();
    void round();
    void show()
    {
        std::cout<<x<<y<<z<<d<<std::endl;
    }
    private:
    Pos x,y,z;
    Direct d;
};

#endif