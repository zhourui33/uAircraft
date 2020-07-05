#ifndef _POSITION_H_
#define _POSITION_H_

#include "orientation.h"
#include "coordinate.h"
#include "base/Role.h"

struct Position : Coordinate, Orientation
{
    Position(const int x, const int y, const int z, const Orientation& d);
    bool operator==(const Position &rhs) const;

    IMPL_ROLE(Coordinate);
    IMPL_ROLE(Orientation);
};

#endif