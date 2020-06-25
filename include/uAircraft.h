#pragma once

#define Pos int

typedef enum
{
    N = 0,
    S,
    E,
    W
}Direct;

class Position 
{
    public:
    Position():x(0),y(0),z(0),d(N){}
    private:
    Pos x,y,z;
    Direct d;
};

class UnmannedAircraft
{
    UnmannedAircraft()
    {
        Position *initp = new Position();
        this->p = initp;
    }
    private:
    Position *p;
};