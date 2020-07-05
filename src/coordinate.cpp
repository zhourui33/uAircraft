#include "coordinate.h"
#include "orientation.h"

Coordinate::Coordinate(int x, int y, int z):x(x),y(y),z(z)
{

}

bool Coordinate::operator==(const Coordinate& rhs) const
{
    return (x == rhs.x) && (y == rhs.y) && (z == rhs.z);
}

namespace
{
    bool OntheGround(int z)
    {
        return 0 == z;
    }
}

Coordinate& Coordinate::up() const
{
    return Coordinate(x, y, z+1);
}

Coordinate& Coordinate::down() const
{
    if(OntheGround(z))
    {
        return Coordinate(x, y, z);
    }
    return Coordinate(x, y, z-1);
}

Coordinate& Coordinate::forward(Orientation& ori) const
{
    return ori.stepforward(x, y, z);
}