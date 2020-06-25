#pragma once

#include "pub.h"
#include "position.h"

class Commander
{
    public:
    Commander(Position ipos):p(ipos){}
    virtual void actionCommand(Command cmd) = 0;

    protected:
    Position p;
};

class UnmannedAircraft
{
    public:
    UnmannedAircraft()
    {
        this->p = Position();
    }
    UnmannedAircraft(Position ipos):p(ipos){}
    const Position& getPosition()
    {
        return this->p;
    }
    const Position& on(Command cmd);

    private:
    Position p;
};