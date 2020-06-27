#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "pub.h"
#include "position.h"

class Commander
{
    public:
    virtual const Position& action(Position& pos) = 0;
};

class FORWARD : public Commander
{
    public:
    const Position& action(Position& pos)
    {
        pos.forward(1);
        return pos;
    }
};

class UP : public Commander
{
    public:
    const Position& action(Position& pos)
    {
        pos.up(1);
        return pos;
    }
};

class DOWN : public Commander
{
    public:
    const Position& action(Position& pos)
    {
        pos.down(1);
        return pos;
    }
};

class LEFT : public Commander
{
    public:
    const Position& action(Position& pos)
    {
        pos.left();
        return pos;
    }
};

class RIGHT : public Commander
{
    public:
    const Position& action(Position& pos)
    {
        pos.right();
        return pos;
    }
};

class ROUND : public Commander
{
    public:
    const Position& action(Position& pos)
    {
        pos.round();
        return pos;
    }
};

class FORWARD_N : public Commander
{
    public:
    FORWARD_N(int n):nstep(n){}
    const Position& action(Position& pos)
    {
        pos.forward(nstep);
        return pos;
    }
    private:
    int nstep;
};

class UP_N : public Commander
{
    public:
    UP_N(int n):nstep(n){}
    const Position& action(Position& pos)
    {
        pos.up(nstep);
        return pos;
    }
    private:
    int nstep;
};

class DOWN_N : public Commander
{
    public:
    DOWN_N(int n):nstep(n){}
    const Position& action(Position& pos)
    {
        pos.down(nstep);
        return pos;
    }
    private:
    int nstep;
};

class REPEAT :public Commander
{
    public:
    REPEAT(Command cmd, int num):repeat_cmd(cmd),repeat_num(num){}
    const Position& action(Position& pos)
    {
        switch(repeat_cmd)
        {
            case UP : LOOP_N(pos.up(1), repeat_num);break;
            case DOWN : LOOP_N(pos.down(1), repeat_num);break;
            case FORWARD : LOOP_N(pos.forward(1), repeat_num);break;
            case RIGHT : LOOP_N(pos.right(), repeat_num);break;
            case LEFT : LOOP_N(pos.left(), repeat_num);break;
            case ROUND :LOOP_N(pos.round(), repeat_num);break;
            default : break;
        }
        return pos;
    }
    private:
    Command repeat_cmd;
    int repeat_num;
};

#endif