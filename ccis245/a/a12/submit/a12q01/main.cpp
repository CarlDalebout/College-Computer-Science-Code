#include <iostream>
#include "Fib1.h"

int main()
{
    int correct[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    std::cout << "Testing Fib1:" << std::endl;
    Fib1 fib1;
    
    for(int i = 0; i < 49; ++i)
    {
        std::cout << "Test " << i << ' ' 
                  << fib1(i) << std::endl;
    }

    return 0;
}
