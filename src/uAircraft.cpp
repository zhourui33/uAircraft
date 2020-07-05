#include "uAircraft.h"
#include "command.h"

UnmannedAircraft::UnmannedAircraft():pos(0,0,0,N)
{
}

const Position& UnmannedAircraft::getPosition()
{
    return pos;
}

const Position& UnmannedAircraft::on(Command& cmd)
{
    cmd.execute(pos.ROLE(Coordinate), pos.ROLE(Orientation));
    return pos;
}