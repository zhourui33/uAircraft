#include "uAircraft.h"
#include "position.h"

UnmannedAircraft::UnmannedAircraft()
{
    this->p = Position();
}

const Position& UnmannedAircraft::getPosition()
{
    return this->p;
}

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

const Position& UnmannedAircraft::on(Commander *cmd)
{
    cmd->action(this->p);
    return this->p;
}
const Position& UnmannedAircraft::on(UP_N cmd)
{
    cmd.action(this->p);
    return this->p;
}
const Position& UnmannedAircraft::on(DOWN_N cmd)
{
    cmd.action(this->p);
    return this->p;
}
const Position& UnmannedAircraft::on(FORWARD_N cmd)
{
    cmd.action(this->p);
    return this->p;
}
const Position& UnmannedAircraft::on(REPEAT cmd)
{
    cmd.action(this->p);
    return this->p;
}