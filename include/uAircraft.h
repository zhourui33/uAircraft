#ifndef _UNMANNEDAIRCRAFT_H_
#define _UNMANNEDAIRCRAFT_H_

#include "position.h"
#include "command.h"

struct UnmannedAircraft
{
    UnmannedAircraft();
    const Position& getPosition();
    const Position& on(Command& cmd);
    private:
    Position pos;
};

#endif