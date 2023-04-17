// Name: Carl
// File: main.cpp

#include <iostream>
#include <cmath>

bool isprime(int n)
{
    if(n<2)
    {
        return false;
    }
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

int pi(double x)
{
    int * numprimes = new int;
    *numprimes = 0;
    for(int i=0; i <= x; ++i)
    {
        if(!isprime(i))
            ++(*numprimes);
    }
    
    int ret = *numprimes;
    delete numprimes;
    return ret;
}

int main()
{
    double x;
    std::cin >> x;
    std::cout << pi(x) << '\n';
    return 0;
}
