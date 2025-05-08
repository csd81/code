#include "example.h"

Example1::Example1():
    Image(8,4)
{
}

bool Example1::pixel(int x, int y) const
{
    if (x==7 || (x==4 && y==2))
        return true;
    else
        return false;

    // vagy: return x==7 || (x==4 && y==2);
}

Example2::Example2():
    Image(10,5)
{
}

bool Example2::pixel(int x, int y) const
{
    return x%3 || y%2;
}
