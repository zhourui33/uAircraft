#include "uAircraft.h"

const Position& UnmannedAircraft::on(Command cmd)
{
    switch(cmd)
    {
        case UP : this->p.up(1);break;
        case DOWN : this->p.down(1);break;
        case FORWARD : this->p.forward(1);break;
        default : break;
    }
    return this->p;
}