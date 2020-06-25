#pragma once

#define POS int

typedef enum
{
    North = 0,
    Sourth,
    East,
    West
}Direct;

class uAircraft
{
    uAircraft():_x(0),_y(0),_z(0),_d(North){};
    uAircraft(POS x, POS y, POS z, Direct d):_x(x),_y(y),_z(z),_d(d){};
    private:
    POS _x, _y, _z;
    Direct _d;
};