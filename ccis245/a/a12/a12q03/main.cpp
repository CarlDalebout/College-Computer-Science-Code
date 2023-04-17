#include <iostream>
#include "Fib1.h"
#include "Fib2.h"
#include "Fib3.h"

int main()
{
    int correct[] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};
    std::cout << "Testing Fib1:" << std::endl;
    Fib1 fib1;
    
    // for(int i = 0; i < 49; ++i)
    // {
    //     std::cout << "Test " << i 
    //               << fib1(i) << std::endl;
    // }

    // std::cout << "Test Fib2:" << std::endl;
    // Fib2 fib2;
    // std::cout << "Test 1 " << (fib2[2] == 0 ? " pass" : " FAIL")
    //           << std::endl;

    // for(int i = 0; i < 10; ++i)
    // {
    //     std::cout << "Test " << i + 2
    //               << (fib2(i) == correct[i] ? " pass" : " FAIL")
    //               << std::endl;
    // }

    // std::cout << "Test 12 " << (fib2[2] == 2 ? " pass" : " FAIL")
    //         << std::endl;

    std::cout << "Test Fib3:" << std::endl;
    Fib3 fib3;
    std::cout << "Test 1" << (Fib3::lookup(2) == -1 ? " pass" : " FAIL")
              << std::endl;

    for(int i = 0; i < 10; ++i)
    {
        std::cout << "Test " << i + 2
                  << (fib3(i) == correct[i] ? " pass" : " FAIL")
                  << std::endl;
    }

    std::cout << "Test 12" << (Fib3::lookup(2)== 2 ? " pass" : " FAIL")
            << std::endl;
    
    return 0;
}
