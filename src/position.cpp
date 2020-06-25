#include "position.h"

inline bool Position::operator==(const Position &pos) const
{
    if(this->x != pos.x || this->y != pos.y || this->z != pos.z || this->d !=pos.d)
        return false;
    return true;
}

inline bool Position::operator!=(const Position &pos) const
{
    if(this->x != pos.x || this->y != pos.y || this->z != pos.z || this->d !=pos.d)
        return true;
    return false;
}

inline void Position::up(int n)
{
    this->z += n;
}
inline void Position::down(int n)
{
    if(this->z != 0 && this->z >= n)
    {
        this->z -= n;
    }
}
inline void Position::forward(int n)
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