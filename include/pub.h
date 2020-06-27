#ifndef _PUB_H_0626
#define _PUB_H_0626

#define SUCCESS 0
#define FAILED 1

#define Pos int
#define LOOP_N(exp, n) do{for(int i=0;i<n;i++){exp;}}while(0);

enum Direct{N, E, S, W};
Direct operator++(Direct& d);
Direct operator--(Direct& d);

enum Command
{
    UP = 0,
    DOWN,
    FORWARD,
    LEFT,
    RIGHT,
    ROUND
};

#endif