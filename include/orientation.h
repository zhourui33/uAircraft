#ifndef _ORIENTATION_H_
#define _ORIENTATION_H_

struct Coordinate;

struct Orientation
{
    bool operator==(const Orientation& rhs) const;
    static const Orientation north;
    static const Orientation south;
    static const Orientation west;
    static const Orientation east;
    Coordinate& stepforward(int x, int y, int z) const;
    Orientation& turnleft() const;
    private:
    Orientation(int direct, int xFactor, int yFactor);
    int direct;
    int xFactor;
    int yFactor;
};

#define N Orientation::north
#define S Orientation::south
#define W Orientation::west
#define E Orientation::east

#endif