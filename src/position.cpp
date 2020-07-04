#include "position.h"

Position::Position():x(0),y(0),z(0),d(N)
{

}
Position::Position(Pos ix, Pos iy, Pos iz, Direct id):x(ix),y(iy),z(iz),d(id)
{
    
}
bool Position::operator==(const Position &pos) const
{
    if(this->x != pos.x || this->y != pos.y || this->z != pos.z || this->d !=pos.d)
        return false;
    return true;
}

void Position::up(int n)
{
    this->z += n;
}
void Position::down(int n)
{
    if(this->z != 0 && this->z >= n)
    {
        this->z -= n;
    }
}
void Position::forward(int n)
{
    switch(this->d)
    {
        case N : this->y += n;break;
        case E : this->x += n;break;
        case S : this->y -= n;break;
        case W : this->x -= n;break;
        default : break;
    }
}

void Position::left()
{
    --this->d;
}
void Position::right()
{
    ++this->d;
}
void Position::round()
{
    ++this->d;
    ++this->d;
}