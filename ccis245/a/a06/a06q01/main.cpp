/************************

Author: Carl Dalebout
Date: 10/10/22
File: main.cpp

************************/

#include <iostream>
#include "fraction.h"

void test_print()
{
    int n = 0, d = 0;
    std::cin >> n >> d;
    Fraction f = {n, d};
    std::cout << f << std::endl;
}

int main()
{
    int option;
    std::cin >> option;

    switch (option)
    {
        case 1:
            test_print();
            break;
    }

    return 0;
}


