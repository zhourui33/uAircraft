#ifndef _COMMAND_H_
#define _COMMAND_H_

struct Coordinate;
struct Orientation;

struct Command
{
    virtual void execute(Coordinate&, Orientation&) const = 0;
};

struct Commands
{
    static Command& up();
    static Command& down();
    static Command& forward();
    static Command& left();
};

struct RepeatableCommand : Command
{
    RepeatableCommand(const Command&, int);
    private:
    virtual void execute(Coordinate&, Orientation&) const;
    bool outOfBound() const;
    const Command& cmd;
    const int times;
};

#define REPEAT(cmd, n) RepeatableCommand(cmd, n)
#define UP Commands::up()
#define DOWN Commands::down()
#define FORWARD Commands::forward()
#define LEFT Commands::left()
#define RIGHT REPEAT(LEFT, 3)
#define ROUND REPEAT(LEFT, 2)
#define FORWARD_N(n) REPEAT(FORWARD, n)
#define UP_N(n) REPEAT(UP, n)
#define DOWN_N(n) REPEAT(DOWN, n)

#endif