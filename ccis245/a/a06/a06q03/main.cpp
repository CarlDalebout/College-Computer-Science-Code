/************************

Author: Carl Dalebout
Date: 10/10/22
File: main.cpp

************************/

#include <iostream>
#include "fraction.h"

void test_print()
{
    Fraction f0;
    std::cin >> f0.n >> f0.d;
    std::cout << f0 << '\n';
}

void test_add()
{
    Fraction f0, f1;
    std::cin >> f0.n >> f0.d >> f1.n >> f1.d;
    std::cout << (f0 + f1) << std::endl;
}

void test_subtract()
{
    Fraction f0, f1;
    std::cin >> f0.n >> f0.d >> f1.n >> f1.d;
    std::cout << (f0 - f1) << std::endl;
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
        case 2:
            test_add();
            break;
        case 3:
            test_subtract();
            break;
    }

    return 0;
}


