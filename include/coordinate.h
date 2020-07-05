#ifndef _COORDINATE_H_
#define _COORDINATE_H_

struct Orientation;

struct Coordinate
{
    Coordinate(int x, int y, int z);
    bool operator==(const Coordinate& rhs) const;
    Coordinate& up() const;
    Coordinate& down() const;
    Coordinate& forward(Orientation& ori) const;
    protected:
    int x,y,z;    
};

#endif