#include <iostream>
#include "Fib2.h"

int Fib2::operator()(const int n)
{
    if( n < 0)
        return 1;
    else if(n < 20)
    {
        if(t[n] == 0)
            t[n] = operator()(n - 1) + operator()(n - 2);
        return t[n];
    }
    else
    {}

    return operator()(n - 1) + operator()(n - 2);
}
