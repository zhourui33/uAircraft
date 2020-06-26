#include "pub.h"

Direct operator++(Direct& d)
{
    switch(d)
    {
        case N : d = E;break;
        case E : d = S;break;
        case S : d = W;break;
        case W : d = N;break;
        default : break;
    }
    return d;
}
Direct operator--(Direct& d)
{
    switch(d)
    {
        case N : d = W;break;
        case E : d = N;break;
        case S : d = E;break;
        case W : d = S;break;
        default : break;
    }
    return d;
}