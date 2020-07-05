#include "orientation.h"
#include "coordinate.h"

namespace
{
    Orientation* ori[4];
}

bool Orientation::operator==(const Orientation& rhs) const
{
    return (direct == rhs.direct) && (xFactor == rhs.xFactor) && (yFactor == rhs.yFactor);
}

Orientation::Orientation(int direct, int xFactor, int yFactor)
    :direct(direct), xFactor(xFactor), yFactor(yFactor)
{
    ori[direct] = this;
}

Coordinate& Orientation::stepforward(int x, int y, int z) const
{
    return Coordinate(x+xFactor, y+yFactor, z);
}

Orientation& Orientation::turnleft() const
{
    return *ori[(direct+1)%4];
}

const Orientation Orientation::north(0, 0, 1);
const Orientation Orientation::west(1, -1, 0);
const Orientation Orientation::south(2, 0, -1);
const Orientation Orientation::east(3, 1, 0);