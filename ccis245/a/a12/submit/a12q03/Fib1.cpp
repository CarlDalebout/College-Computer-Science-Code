#include <iostream>
#include "Fib1.h"

int Fib1::operator()(const int n)
{
    if (n <= 1)
        return 1;
    else
        return operator()(n - 1) + operator()(n - 2);
}
