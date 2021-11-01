#include "../inc/libmx.h"

int mx_sqrt(int x)
{
    int squareRoot = 0;
    int i = 1;
    while (squareRoot * squareRoot < x)
    {
        squareRoot += i;
    }
    if (squareRoot * squareRoot > x)
    {
        return 0;
    }
    return squareRoot;
}
