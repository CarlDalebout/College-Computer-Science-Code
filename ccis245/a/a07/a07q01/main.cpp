/**************************
Author: Carl Dalebout
File: main.cpp
***************************/

#include <iostream>
#include "Rational.h"

void mem_init()
{
    int n, d;
    std::cin >> n >> d;
    Rational test = { n, d };    

    std::cout << '<' << test.get_n() << ", " << test.get_d() << ">\n";
}

void mem_reduce()
{
    int n, d;
    std::cin >> n >> d;
    Rational test = { n, d };
    test.reduce();

    std::cout << '<' << test.get_n() << ", " << test.get_d() << ">\n";
}

void mem_equal_to()
{
    int n1, d1, n2, d2;

    std::cin >> n1 >> d1 >> n2 >> d2;

    Rational test1 = { n1, d1 };
    Rational test2 = { n2, d2 };
    
    std::cout << (test1 == test2) << ' ' << test1 << ' ' << test2 << '\n';
}

void mem_not_equal_to()
{
    int n1, d1, n2, d2;

    std::cin >> n1 >> d1 >> n2 >> d2;

    Rational test1 = { n1, d1 };
    Rational test2 = { n2, d2 };
    
    std::cout << (test1 != test2) << ' ' << test1 << ' ' << test2 << '\n';
}

void mem_is_greater_then()
{
    int n1, d1, n2, d2;

    std::cin >> n1 >> d1 >> n2 >> d2;

    Rational test1 = { n1, d1 };
    Rational test2 = { n2, d2 };
    
    std::cout << (test1 > test2) << ' ' << test1 << ' ' << test2 << '\n';
}

void mem_is_greater_then_equal_to()
{
    int n1, d1, n2, d2;

    std::cin >> n1 >> d1 >> n2 >> d2;

    Rational test1 = { n1, d1 };
    Rational test2 = { n2, d2 };

    std::cout << (test1 >= test2) << ' ' << test1 << ' ' << test2 << '\n';
}

void mem_is_less_then()
{
    int n1, d1, n2, d2;

    std::cin >> n1 >> d1 >> n2 >> d2;

    Rational test1 = { n1, d1 };
    Rational test2 = { n2, d2 };

    std::cout << (test1 < test2) << ' ' << test1 << ' ' << test2 << '\n';
}

void mem_is_less_then_equal_to()
{
    int n1, d1, n2, d2;

    std::cin >> n1 >> d1 >> n2 >> d2;

    Rational test1 = { n1, d1 };
    Rational test2 = { n2, d2 };

    std::cout << (test1 <= test2) << ' ' << test1 << ' ' << test2 << '\n';
}

void mem_add_equal()
{
    Rational test1, test2;
    std::cin >> test1 >> test2;

    std::cout << (test1 += test2) << ' ' << test1 << ' ' << test2 << '\n';
}

void mem_sub_equal()
{
    Rational test1, test2;
    std::cin >> test1 >> test2;

    std::cout << (test1 -= test2) << ' ' << test1 << ' ' << test2 << '\n';
}

void mem_mult_equal()
{
    Rational test1, test2;
    std::cin >> test1 >> test2;
    
    std::cout << (test1 *= test2) << ' ' << test1 << ' ' << test2 << '\n';
}

void mem_div_equal()
{
    Rational test1, test2;
    std::cin >> test1 >> test2;

    std::cout << (test1 /= test2) << ' ' << test1 << ' ' << test2 << '\n';
}

void mem_plus()
{
    Rational test;
    std::cin >> test;

    std::cout << +test << test << '\n';
}

void mem_minus()
{
    Rational test;
    std::cin >> test;

    std::cout << -test << test << '\n';
}

void mem_add()
{
    Rational test1, test2;
    std::cin >> test1 >> test2;

    std::cout << (test1 + test2) << ' ' << test1 << ' ' << test2 << '\n';
}

void mem_sub()
{
    Rational test1, test2;
    std::cin >> test1 >> test2;

    std::cout << (test1 - test2) << ' ' << test1 << ' ' << test2 << '\n';
}

void mem_mult()
{
    Rational test1, test2;
    std::cin >> test1 >> test2;

    std::cout << (test1 * test2) << ' ' << test1 << ' ' << test2 << '\n';
}

void mem_div()
{
    Rational test1, test2;
    std::cin >> test1 >> test2;

    std::cout << (test1 / test2) << ' ' << test1 << ' ' << test2 << '\n';
}

void mem_abs()
{
    int n, d;
    std::cin >> n >> d;

    Rational test = { n, d };

    std::cout << "the abs of " << test << " is " << test.abs() << '\n';
}

void mem_pow()
{
    int n, d, v;
    std::cin >> n >> d >> v;

    Rational test = { n, d };

    std::cout << test << " to the " << v << " power is " << test.pow(v) << '\n';
}

void mem_get_int()
{
    int n, d;
    std::cin >> n >> d;

    Rational test = { n, d };

    std::cout << "the int value of test is " << test.get_int() << '\n';
}

void mem_get_double()
{
    int n, d;
    std::cin >> n >> d;

    Rational test = { n, d };

    std::cout << "the double value of test is " << test.get_double() << '\n';
}

void non_mem_reduce()
{
    Rational test;
    std::cin >> test;

    std::cout << test << ' '; 
    
    reduce(test);

    std::cout << test << '\n';
}

void non_mem_ads()
{
    Rational test;
    std::cin >> test;

    std::cout << test << ' ' << abs(test) << '\n';
}

void non_mem_pow()
{
    Rational test;
    int v;
    std::cin >> test >> v;

    std::cout << test << ' ' << pow(test, v) << '\n';
}

void non_mem_equal_equal()
{
    Rational test1, test2;
    std::cin >> test1 >> test2;

    std::cout << (test1 == test2) << ' ' << test1 << ' ' << test2 << '\n';
}

void non_mem_not_equal()
{
    Rational test1, test2;
    std::cin >> test1 >> test2;

    std::cout << (test1 != test2) << ' ' << test1 << ' ' << test2 << '\n';
}

void non_mem_is_greater_then()
{
    Rational test1, test2;
    std::cin >> test1 >> test2;

    std::cout << (test1 > test2) << ' ' << test1 << ' ' << test2 << '\n';
}

void non_mem_is_greater_then_equal_to()
{
    Rational test1, test2;
    std::cin >> test1 >> test2;

    std::cout << (test1 >= test2) << ' ' << test1 << ' ' << test2 << '\n';
}

void non_mem_is_less_then()
{
    Rational test1, test2;
    std::cin >> test1 >> test2;

    std::cout << (test1 < test2) << ' ' << test1 << ' ' << test2 << '\n';
}

void non_mem_is_less_then_equal_to()
{
    Rational test1, test2;
    std::cin >> test1 >> test2;

    std::cout << (test1 <= test2) << ' ' << test1 << ' ' << test2 << '\n';
}

void non_mem_add_equal()
{
    int v;
    Rational test;
    std::cin >> v >> test;

    std::cout << '{' << v << '}' << ' '
              << (v += test)     << ' '
              << '{' << v << '}' << ' '
              <<  test << '\n';
}

void non_mem_sub_equal()
{
    int v;
    Rational test;
    std::cin >> v >> test;

    std::cout << '{' << v << '}' << ' '
              << (v -= test)     << ' '
              << '{' << v << '}' << ' '
              <<  test << '\n';
}

void non_mem_mult_equal()
{
    int v;
    Rational test;
    std::cin >> v >> test;

    std::cout << '{' << v << '}' << ' '
              << (v *= test)     << ' '
              << '{' << v << '}' << ' '
              <<  test << '\n';
}

void non_mem_div_equal()
{
    int v;
    Rational test;
    std::cin >> v >> test;

    std::cout << '{' << v << '}' << ' '
              << (v /= test)     << ' '
              << '{' << v << '}' << ' '
              <<  test << '\n';
}

void non_mem_add()
{
    int v;
    Rational test;
    std::cin >> v >> test;

    std::cout << '{' << v << '}' << ' '
              << (v + test)     << ' '
              << '{' << v << '}' << ' '
              <<  test << '\n';
}

void non_mem_sub()
{
    int v;
    Rational test;
    std::cin >> v >> test;

    std::cout << '{' << v << '}' << ' '
              << (v - test)     << ' '
              << '{' << v << '}' << ' '
              <<  test << '\n';
}

void non_mem_mult()
{
    int v;
    Rational test;
    std::cin >> v >> test;

    std::cout << '{' << v << '}' << ' '
              << (v * test)     << ' '
              << '{' << v << '}' << ' '
              <<  test << '\n';
}

void non_mem_div()
{
    int v;
    Rational test;
    std::cin >> v >> test;

    std::cout << '{' << v << '}' << ' '
              << (v / test)     << ' '
              << '{' << v << '}' << ' '
              <<  test << '\n';
}

int main()
{
    int option;
    std::cin >> option;

    switch (option)
    {
        case 0:
            mem_init();
            break;
        case 1:
            mem_reduce();
            break;
        case 2:
            mem_equal_to();
            break;
        case 3:
            mem_not_equal_to();
            break;
        case 4:
            mem_is_greater_then();
            break;
        case 5:
            mem_is_greater_then_equal_to();
            break;
        case 6:
            mem_is_less_then();
            break;
        case 7:
            mem_is_less_then_equal_to();
            break;
        case 8:
            mem_add_equal();
            break;
        case 9:
            mem_sub_equal();
            break;
        case 10:
            mem_mult_equal();
            break;
        case 11:
            mem_div_equal();
            break;
        case 12:
            mem_plus();
            break;
        case 13:
            mem_minus();
            break;
        case 14:
            mem_add();
            break;
        case 15:
            mem_sub();
            break;
        case 16:
            mem_mult();
            break;
        case 17:
            mem_div();
            break;
        case 18:
            mem_abs();
            break;
        case 19:
            mem_pow();
            break;
        case 20:
            mem_get_int();
            break;
        case 21:
            mem_get_double();
            break;
        case 22:
            non_mem_reduce();
            break;
        case 23:
            non_mem_ads();
            break;
        case 24:
            non_mem_pow();
            break;
        case 25:
            non_mem_equal_equal();
            break;
        case 26:
            non_mem_not_equal();
            break;
        case 27:
            non_mem_is_greater_then();
            break;
        case 28:
            non_mem_is_greater_then_equal_to();
            break;
        case 29:
            non_mem_is_less_then();
            break;
        case 30:
            non_mem_is_less_then_equal_to();
            break;
        case 31:
            non_mem_add_equal();
            break;
        case 32:
            non_mem_sub_equal();
            break;
        case 33:
            non_mem_mult_equal();
            break;
        case 34:
            non_mem_div_equal();
            break;
        case 35:
            non_mem_add();
            break;
        case 36:
            non_mem_sub();
            break;
        case 37:
            non_mem_sub();
            break;
        case 38:
            non_mem_mult();
            break;
        case 39:
            non_mem_div();
            break;
    }
    return 0;
}
