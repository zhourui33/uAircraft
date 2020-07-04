#pragma once

#include "pub.h"
#include "position.h"
#include "commander.h"

class UnmannedAircraft
{
    public:
    UnmannedAircraft();
    const Position& getPosition();
    const Position& on(Command cmd);
    const Position& on(Commander *cmd);
    const Position& on(UP_N cmd);
    const Position& on(DOWN_N cmd);
    const Position& on(FORWARD_N cmd);
    const Position& on(REPEAT cmd);
    private:
    Position p;
};