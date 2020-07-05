#include "command.h"
#include "coordinate.h"
#include "orientation.h"
#include "base/Singleton.h"

Command& Commands::up()
{
    DEF_SINGLETON(UpCommand)EXTENDS(Command)
    {
        private:
        virtual void execute(Coordinate& coor, Orientation&) const
        {
            coor = coor.up();
        }
    };
    return UpCommand::getInstance();
}

Command& Commands::down()
{
    DEF_SINGLETON(DownCommand)EXTENDS(Command)
    {
        private:
        virtual void execute(Coordinate& coor, Orientation&) const
        {
            coor = coor.down();
        }
    };
    return DownCommand::getInstance();
}

Command& Commands::forward()
{
    DEF_SINGLETON(ForwardCommand)EXTENDS(Command)
    {
        private:
        virtual void execute(Coordinate& coor, Orientation& ori) const
        {
            coor = coor.forward(ori);
        }
    };
    return ForwardCommand::getInstance();
}

Command& Commands::left()
{
    DEF_SINGLETON(LeftCommand)EXTENDS(Command)
    {
        private:
        virtual void execute(Coordinate&, Orientation& ori) const
        {
            ori = ori.turnleft();
        }
    };
    return LeftCommand::getInstance();
}

RepeatableCommand::RepeatableCommand(const Command& cmd, int n):cmd(cmd), times(n)
{
}

bool RepeatableCommand::outOfBound() const
{
    return times < 0 || times > 10;
}

void RepeatableCommand::execute(Coordinate& coor, Orientation& ori) const
{
    if(outOfBound()) return;
    for(int i = 0; i< times; ++i)
    {
        cmd.execute(coor, ori);
    }
}
