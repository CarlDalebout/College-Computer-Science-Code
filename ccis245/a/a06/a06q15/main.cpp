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

void test_multiply()
{
    Fraction f0, f1;
    std::cin >> f0.n >> f0.d >> f1.n >> f1.d;
    std::cout << (f0 * f1) << std::endl;
}

void test_divid()
{
    Fraction f0, f1;
    std::cin >> f0.n >> f0.d >> f1.n >> f1.d;
    std::cout << (f0 / f1) << std::endl;
}

void test_equal_to()
{
    Fraction f0, f1;
    std::cin >> f0.n >> f0.d >> f1.n >> f1.d;
    std::cout << (f0 == f1) << std::endl;
}

void test_not_equal_to()
{
    Fraction f0, f1;
    std::cin >> f0.n >> f0.d >> f1.n >> f1.d;
    std::cout << (f0 != f1) << std::endl;
}

void test_reduce()
{
    Fraction f0;
    std::cin >> f0.n >> f0.d;
    reduce(f0);
    std::cout << f0 << std::endl;
}

void test_get_Fraction()
{
    int n, d;
    std::cin >> n >> d;
    Fraction f = get_Fraction(n,d);
    std::cout << f << std::endl;
}

void test_get_n()
{
    int n, d;
    std::cin >> n >> d;
    Fraction f = get_Fraction(n,d);
    std::cout << get_n(f) << std::endl;
}

void test_get_d()
{
    int n, d;
    std::cin >> n >> d;
    Fraction f = get_Fraction(n,d);
    std::cout << get_d(f) << std::endl;

}

void test_set_n()
{
    int n, d;
    std::cin >> n >> d;
    Fraction f = get_Fraction(n,d);
    std::cin >> n;
    set_n(f, n);
    std::cout << f << std::endl;
}

void test_set_d()
{
    int n, d;
    std::cin >> n >> d;
    Fraction f = get_Fraction(n,d);
    std::cin >> d;
    set_d(f, d);
    std::cout << f << std::endl;
}

void test_set()
{
    int n, d;
    std::cin >> n >> d;
    Fraction f = get_Fraction(n,d);
    std::cin >> n >> d;
    set(f, n, d);
    std::cout << f << std::endl;
}

void test_get_int()
{
    int n, d;
    std::cin >> n >> d;
    std::cout << get_int(get_Fraction(n,d)) << std::endl;
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
        case 4:
            test_multiply();
            break;
        case 5:
            test_divid();
            break;
        case 6:
            test_equal_to();
            break;
        case 7:
            test_not_equal_to();
            break;
        case 8:
            test_reduce();
            break;
        case 9:
            test_get_Fraction();
            break;
        case 10:
            test_get_n();
            break;
        case 11:
            test_get_d();
            break;
        case 12:
            test_set_n();
            break;
        case 13:
            test_set_d();
            break;
        case 14:
            test_set();
            break;
        case 15:
            test_get_int();
            break;
    }

    return 0;
}


