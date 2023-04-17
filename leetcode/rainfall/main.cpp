#include <iostream>
#include <stdlib.h>
#include "time.h"

void print(int *x, int n)
{
    std::string dir = "";
    std::cout << '[';
    for(int i = 0; i < n; ++i)
    {
        std::cout << dir << x[i]; dir = ", ";
    }
    std::cout << "]\n";
}

int main()
{
    srand(time(NULL));
    int *x;
    int n;
    std::cin >> n;
    x = new int[n]; 
    for(int i = 0; i < n; ++i)
    {
        x[i] = rand()%10;
    }

    for(int i = 0; i < n-1; ++i)
    {
        if(x[i+1] < x[i])
        {

        }
    }

    print(x, n);

    delete[] x;
    return 0;
}