#include <iostream>
#include "Fib3.h"

int Fib3::t[20]= { 1,  1, -1, -1, -1, -1, -1, -1, -1, -1,
                  -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

int Fib3::operator()(const int n)
{
    if( n < 0)
        return 1;
    else if(n < 20)
    {
        if(lookup(n) == -1)
            set(n) = (operator()(n - 1) + operator()(n - 2));
        return lookup(n);
    }
    else
    {}

    return operator()(n - 1) + operator()(n - 2);
}
