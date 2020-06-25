#ifndef _POSITION_H_
#define _POSITION_H_

#include "pub.h"

class Position 
{
    public:
    Position():x(0),y(0),z(0),d(N){}
    Position(Pos ix, Pos iy, Pos iz, Direct id):x(ix),y(iy),z(iz),d(id){}
    inline bool operator==(const Position &pos) const;
    inline bool operator!=(const Position &pos) const;
    inline void up(int n);
    inline void down(int n);
    inline void forward(int n);
    private:
    Pos x,y,z;
    Direct d;
};

#endif