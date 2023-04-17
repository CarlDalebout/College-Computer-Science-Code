//File: main.cpp
//Author: Carl Dalebout

#include <iostream>
#include "IntDynArr.h"

#define SIZE(x) (sizeof(x)/sizeof(int))

void test_IntDynArr()
{
    IntDynArr a;
    std::cin >> a;
    std::cout << a << std::endl;
}

void test_IntDynArr_size()
{
    int size;
    std::cin >> size;
    IntDynArr a(size);
    std::cout << a << std::endl;
}

void test_IntDynArr_array()
{
    int x[] = {1, 2, -4, 0};
    IntDynArr a(SIZE(x), x);
    std::cout << a << std::endl;
}

void test_IntDynArr_copy()
{
    IntDynArr a;
    std::cin >> a;
    IntDynArr b(a);
    std::cout << b;
}

void test_get_size()
{
    IntDynArr a;
    std::cin >> a;
    std::cout << a.get_size() << std::endl;
}

void test_get_capacity()
{
    IntDynArr a;
    std::cin >> a;
    std::cout << a.get_capacity() << std::endl;
}

void test_eq()
{
    IntDynArr a, b;
    std::cin >> a >> b;
    std::cout << (a == b) << std::endl;
}

void test_plus_not_eq()
{
    IntDynArr a, b;
    std::cin >> a >> b;
    std::cout << (a != b) << std::endl;
}

void test_assign()
{
    IntDynArr a;
    std::cin >> a;
    IntDynArr b = a;
    std::cout << b << std::endl;
}

void test_resize()
{
    IntDynArr a;
    int N;
    std::cin >> a >> N;
    a.resize(N);
    a.print();
}

void test_plus_eq()
{
    IntDynArr a, b;
    std::cin >> a >> b;
    std::cout << (a += b) << ' ';
    std::cout << a << ' ';
    std::cout << ((a+=b) += b) << std::endl;
}

void test_plus()
{
    IntDynArr a, b;
    std::cin >> a >> b;
    std::cout << (a + b) << ' ';
    std::cout << a << ' ';
    std::cout << ((a + b) + b) << std::endl;
}

void test_insert()
{
    IntDynArr a;
    int index, value;
    std::cin >> a >> index >> value;
    a.insert(index, value);
    std::cout << a << std::endl;
}

void test_remove()
{
    IntDynArr a;
    int i;
    std::cin >> a >> i;
    std::cout << a << ' ' << a.remove(i) << std::endl;
}

void test_subarry()
{
    IntDynArr a;
    int index, length;
    std::cin >> a >> index >> length;
    std::cout << a.subarray(index, length) << std::endl;
}

void test_print()
{
    int x[] = {1, 2, -4, 0};
    IntDynArr a(SIZE(x), x);
    a.print();
}

int main()
{
    int option;
    std::cin >> option;
    switch(option)
    {
        case 0:
            test_IntDynArr();
            break;
        case 1:
            test_IntDynArr_size();
            break;
        case 2:
            test_IntDynArr_array();
            break;
        case 3:
            test_IntDynArr_copy();
            break;
        case 4:
            test_get_size();
            break;
        case 5:
            test_get_capacity();
            break;
        case 6:
            test_eq();
            break;
        case 7:
            test_plus_not_eq();
            break;
        case 8:
            test_assign();
            break;
        case 9:
            test_resize();
            break;
        case 10:
            test_plus_eq();
            break;
        case 11:
            test_plus();
            break;
        case 12:
            test_insert();
            break;
        case 13:
            test_remove();
            break;
        case 14:
            test_subarry();
            break;
        case 15:
            test_print();
            break;            
    }
    
    return 0;
}
