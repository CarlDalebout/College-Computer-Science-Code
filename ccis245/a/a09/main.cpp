//File: main.cpp
//Author: Carl Dalebout

#include <iostream>
#include "Mystring.h"

void test_constructor()
{
    Mystring s;
    std::cout << s << std::endl;
}

void test_constructor_char()
{
    char c;
    std::cin >> c;
    Mystring s(c);
    std::cout << s << std::endl;
}

void test_constructor_char_array()
{
    char s[100];
    std::cin >> s;
    Mystring x(s);
    std::cout << x << std::endl;
}

void test_copy_constructor()
{
    char s[100];
    std::cin >> s;
    Mystring x(s);
    Mystring y(x);
    std::cout << y << std::endl;
}

void test_input()
{
    Mystring x;
    std::cin >> x;
    std::cout << x << '\n' ;
}

void test_eq()
{
    Mystring x, y;
    std::cin >> x >> y;
    std::cout << (x == y) << std::endl;
}

void test_ne()
{
    Mystring x, y;
    std::cin >> x >> y;
    std::cout << (x != y) << std::endl;
}

void test_assign()
{
    Mystring x, y;
    std::cin >> x;
    y = x;
    std::cout << y << std::endl;
}

void test_empty()
{
    Mystring x;
    std::cout << x.clear() << std::endl;
}

void test_bracket_const()
{
    Mystring x;
    int i = 0;
    std::cin >> x >> i;
    std::cout << x[i] << std::endl;
}

void test_bracket()
{
    Mystring x;
    int i = 0;
    char c;
    std::cin >> x >> i >> c;
    x[i] = c;
    std::cout << x << std::endl;
}

void test_pluseq_mystring()
{
    Mystring x, y, z;
    std::cin >> x >> y >> z;
    (x += y) += z;
    std::cout << x << std::endl;
}

void test_pluseq_char()
{
    Mystring x;
    char c, d;
    std::cin >> x >> c >> d;
    (x += c) += d;
    std::cout << x << std::endl;
}

void test_plus()
{
    Mystring x, y;
    std::cin >> x >> y;
    std::cout << x + y << std::endl;
}

void test_plus_char()
{
    Mystring x, y;
    char c;
    std::cin >> x >> c;
    std::cout << x + c << std::endl;
}

void test_resize()
{
    Mystring x;
    int i = 0;
    std::cin >> x >> i;
    x.resize(i);
    std::cout << x << std::endl;
}

void test_resize_char()
{
    Mystring x;
    int i = 0;
    char c;
    std::cin >> x >> i >> c;
    x.resize(i, c);
    std::cout << x << std::endl;
}

void test_find_char_int()
{
    Mystring x;
    char c;
    int i = 0;
    std::cin >> x >> c >> i;
    std::cout << x.find(c , i) << std::endl;
}

void test_find()
{
    Mystring x, y;
    std::cin >> x >> y;
    std::cout << x.find(y) << std::endl;
}

void test_substr()
{
    Mystring x, y;
    int i, len;
    std::cin >> x >> i >> len;
    std::cout << x.substr(i, len) << std::endl;
}

int main()
{
    int option;
    std::cin >> option;
    switch(option)
    {
        case 1:
            test_constructor();
            break;
        case 2:
            test_constructor_char();
            break;
        case 3:
            test_constructor_char_array();
            break;
        case 4:
            test_copy_constructor();
            break;
        case 5:
            test_input();
            break;
        case 6:
            test_eq();
            break;
        case 7:
            test_ne();
            break;
        case 8:
            test_assign();
            break;
        case 9:
            test_empty();
            break;
        case 10:
            test_bracket_const();
            break;
        case 11:
            test_bracket();
            break;
        case 12:
            test_pluseq_mystring();
            break;
        case 13:
            test_pluseq_char();
            break;
        case 14:
            test_plus();
            break;
        case 15:
            test_plus_char();
            break;
        case 16:
            test_resize();
            break;
        case 17:
            test_resize_char();
            break;
        case 18:
            test_find_char_int();
            break;
        case 19:
            test_find();
            break;
        case 20:
            test_substr();
            break;
    }
    return 0;
}
