#include "stdio.h"

int isodd(int x)
{
    if ((x & 1) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}