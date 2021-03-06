#ifndef _UNMANNEDAIRCRAFT_H_
#define _UNMANNEDAIRCRAFT_H_

#include "position.h"
struct Command;

struct UnmannedAircraft
{
    UnmannedAircraft();
    const Position& getPosition();
    const Position& on(const Command& cmd);
    private:
    Position pos;
};

#endif