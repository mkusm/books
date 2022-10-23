#include "Chapter6.h"

long fact(int val)
{
    long ret = 1;
    for (int i = 2; i <= val; i++)
        ret *= i;
    return ret;
}
