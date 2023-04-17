/******************************************************************************
File  : main.cpp
Author: Carl Dalebout
Date  : 10/24/2022
******************************************************************************/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include "vec2d.h"

void test_vec2d_double_double()
{
    double x,y;
    std::cin >> x >> y;
    std::cout << vec2d(x,y) << std::endl;
}

void test_vec2d_default()
{
    vec2d u;
    std::cout << u << std::endl;
}

void test_eq()
{
    vec2d u, v;
    std::cin >> u >> v;
    std::cout << (u == v) << std::endl;
}

void test_neq()
{
    vec2d u, v;
    std::cin >> u >> v;
    std::cout << (u != v) << std::endl;
}

void test_get_x()
{
    vec2d u;
    std::cin >> u;
    std::cout << u << " X: " << u.x() << std::endl;
}

void test_get_y()
{
    vec2d u;
    std::cin >> u;
    std::cout << u << " Y: " << u.y() << std::endl;
}

void test_set_x()
{
    vec2d u;
    int v;
    std::cin >> v;
    u.x() = v;
    std::cout << u << std::endl;
}

void test_set_y()
{
    vec2d u;
    int v;
    std::cin >> v;
    u.y() = v;
    std::cout << u << std::endl;
}

void test_bracket()
{
    vec2d u;
    double x = 0, y = 0;
    std::cin >> x >> y;
    u[0] = x;
    u[1] = y;
    std::cout << u << u[0] << u[1] <<std::endl;
}

void test_plus()
{
    vec2d u;
    std::cin >> u;
    std::cout << (+u) << std::endl;
}

void test_negative()
{
    vec2d u;
    std::cin >> u;
    std::cout << (-u) << std::endl;
}

void test_add()
{
    vec2d u, v;
    std::cin >> u >> v;
    std::cout << (u + v) << std::endl;
}

void test_sub()
{
    vec2d u, v;
    std::cin >> u >> v;
    std::cout << (u - v) << std::endl;
}

void test_mult()
{
    vec2d u;
    int v;
    std::cin >> u >> v;
    std::cout << (u * v) << std::endl;
}

void test_div()
{
    vec2d u;
    int v;
    std::cin >> u >> v;
    std::cout << (u / v) << std::endl;
}

void test_add_eq()
{
    vec2d u, v;
    std::cin >> u >> v;
    std::cout << u << "+=" << v << std::endl;
    u += v;
    std::cout << u << std::endl;
}

void test_sub_eq()
{
    vec2d u, v;
    std::cin >> u >> v;
    std::cout << u << "-=" << v << std::endl;
    u -= v;
    std::cout << u << std::endl;
}

void test_mult_eq()
{
    vec2d u;
    int v;
    std::cin >> u >> v;
    std::cout << u << "*=" << v << std::endl;
    u *= v;
    std::cout << u << std::endl;
}

void test_div_eq()
{
    vec2d u;
    int v;
    std::cin >> u >> v;
    std::cout << u << "/=" << v << std::endl;
    u /= v;
    std::cout << u << std::endl;
}

void test_mult_double_vec2d()
{
    vec2d v;
    int u;
    std::cin >> u >> v;
    std::cout << (u * v) << std::endl;
}

void test_len()
{
    vec2d v;
    std::cin >> v;
    std::cout << len(v) << std::endl;
}

void test_dotpro()
{
    vec2d u, v;
    std::cin >> u >> v;
    std::cout << dotpro(u , v) << std::endl; 
}

void test_norm()
{
    vec2d v;
    std::cin >> v;
    std::cout << norm(v) << std::endl;
}

int main()
{
    int option;
    std::cin>> option;

    switch(option)
    {
        case 0:
            test_vec2d_double_double();
            break;
        case 1:
            test_vec2d_default();
            break;
        case 2:
            test_eq();
            break;
        case 3:
            test_neq();
            break;
        case 4:
            test_get_x();
            break;
        case 5:
            test_get_y();
            break;
        case 6:
            test_set_x();
            break;
        case 7:
            test_set_y();
            break;
        case 8:
            test_bracket();
            break;
        case 9:
            test_plus();
            break;
        case 10:
            test_negative();
            break;
        case 11:
            test_add();
            break;
        case 12:
            test_sub();
            break;
        case 13:
            test_mult();
            break;
        case 14:
            test_div();
            break;
        case 15:
            test_add_eq();
            break;
        case 16:
            test_sub_eq();
            break;
        case 17:
            test_mult_eq();
            break;
        case 18:
            test_div_eq();
            break;
        case 19:
            test_mult_double_vec2d();
            break;
        case 20:
            test_len();
            break;
        case 21:
            test_dotpro();
            break;
        case 22:
            test_norm();
            break;
    }
    return 0;
}
