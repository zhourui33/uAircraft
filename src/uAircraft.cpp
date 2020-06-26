#include "uAircraft.h"

const Position& UnmannedAircraft::on(Command cmd)
{
    switch(cmd)
    {
        case UP : this->p.up(1);break;
        case DOWN : this->p.down(1);break;
        case FORWARD : this->p.forward(1);break;
        case RIGHT : this->p.right();break;
        case LEFT : this->p.left();break;
        case ROUND :this->p.round();break;
        default : break;
    }
    return this->p;
}