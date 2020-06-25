#ifndef _PUB_H_
#define _PUB_H_

#define SUCCESS 0
#define FAILED 1

#define Pos int

typedef enum
{
    N = 0,
    S,
    E,
    W
}Direct;

typedef enum
{
    UP = 0,
    DOWN,
    FORWARD
}Command;
#endif