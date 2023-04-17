// File  : main.cpp
// Author: smaug
#include <iostream>
#include "Fraction.h"

void test_Fraction_print();

void test_Fraction_add();

void test_Fraction_sub();

void test_Fraction_mult();

void test_Fraction_div();

void test_Fraction_addeq();

void test_Fraction_eq();

void test_Fraction_neq();

void test_Fraction_lt();

int main()
{
    int option;

    std::cin >> option;

    switch (option)
    {
        case 1:
            test_Fraction_print();
            break;
        case 2:
            test_Fraction_add();
            break;
        case 3:
            test_Fraction_sub();
            break;
        case 4:
            test_Fraction_mult();
            break;
        case 5:
            test_Fraction_div();
            break;
        case 6:
            test_Fraction_eq();
            break;
        case 7:
            test_Fraction_neq();
            break;
        case 8:
            test_Fraction_lt();
            break;
    }
    
    return 0;
}

void test_Fraction_print()
    {
    int n = 0, d = 0; // numerator and denominator of a fraction
    std::cin >> n >> d;
    Fraction_print(n, d);
    std::cout << std::endl;
}

void test_Fraction_add()
{
    int xn = 0, xd = 0; // Fraction xn/xd
    int yn = 0, yd = 0; // Fraction yn/yd
    int zn = 0, zd = 0; // Fraction zn/zd

    std::cin >> xn >> xd >> yn >> yd;
    Fraction_add(xn, xd, yn, yd, zn, zd);
    Fraction_print(zn, zd);
    std::cout << std::endl;
}

void test_Fraction_sub()
{
    int xn = 0, xd = 0; // Fraction xn/xd
    int yn = 0, yd = 0; // Fraction yn/yd
    int zn = 0, zd = 0; // Fraction zn/zd
    
    std::cin >> xn >> xd >> yn >> yd;
    Fraction_sub(xn, xd, yn, yd, zn, zd);
    Fraction_print(zn, zd);
    std::cout << std::endl;
}

void test_Fraction_mult()
{
    int xn = 0, xd = 0; // Fraction xn/xd
    int yn = 0, yd = 0; // Fraction yn/yd
    int zn = 0, zd = 0; // Fraction zn/zd
    
    std::cin >> xn >> xd >> yn >> yd;
    Fraction_mult(xn, xd, yn, yd, zn, zd);
    Fraction_print(zn, zd);
    std::cout << std::endl;
}

void test_Fraction_div()
{
    int xn = 0, xd = 0; // Fraction xn/xd
    int yn = 0, yd = 0; // Fraction yn/yd
    int zn = 0, zd = 0; // Fraction zn/zd
    
    std::cin >> xn >> xd >> yn >> yd;
    Fraction_div(xn, xd, yn, yd, zn, zd);
    Fraction_print(zn, zd);
    std::cout << std::endl;
}

void test_Fraction_addeq()
{
    int xn = 0, xd = 0; // Fraction xn/xd
    int yn = 0, yd = 0; // Fraction yn/yd
    
    std::cin >> xn >> xd >> yn >> yd;
    Fraction_addeq(xn, xd, yn, yd);
    Fraction_print(xn, xd);
    std::cout << std::endl;
}

void test_Fraction_eq()
{
    int xn = 0, xd = 0; //Fraction xn/xd
    int yn = 0, yd = 0; //Fraction yn/yd

    std::cin >> xn >> xd >> yn >> yd;
    std::cout << Fraction_eq(xn, xd, yn, yd);
    std::cout << std::endl;
}

void test_Fraction_neq()
{
    int xn = 0, xd = 0; //Fraction xn/xd
    int yn = 0, yd = 0; //Fraction yn/yd
    
    std::cin >> xn >> xd >> yn >> yd;
    std::cout << Fraction_neq(xn, xd, yn, yd);
    std::cout << std::endl;
}

void test_Fraction_lt()
{
    int xn = 0, xd = 0; //Fraction xn/xd
    int yn = 0, yd = 0; //Fraction yn/yd
    
    std::cin >> xn >> xd >> yn >> yd;
    std::cout << Fraction_lt(xn, xd, yn, yd);
    std::cout << std::endl;
}
    
