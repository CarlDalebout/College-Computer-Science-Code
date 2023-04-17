//Author: Carl Dalebout
//File: main.cpp

#include <iostream>
#include <limits>
#include "mystring.h"

const int MAX_BUF = 1024;

void test_str_cmp()
{
    char s[MAX_BUF];
    char t[MAX_BUF];

    std::cin.getline(s, MAX_BUF);
    std::cin.getline(t, MAX_BUF);

    std::cout << str_cmp(s,t) << std::endl;
}

void test_str_cpy()
{
    char x[MAX_BUF];
    char y[MAX_BUF];

    std::cin.getline(y, MAX_BUF);
    str_cpy(x,y);
    std::cout << x << std::endl;
    return;
}

void test_str_chr()
{
    char x[MAX_BUF];
    char c;

    std::cin.getline(x, MAX_BUF);
    std::cin >> c;

    std::cout << str_chr(x,c) << std::endl;
    return;
}

void test_str_str()
{
    char x[MAX_BUF];
    char y[MAX_BUF];

    std::cin.getline(x, MAX_BUF);
    std::cin.getline(y, MAX_BUF);

    std::cout << str_str(x, y) << std::endl;
    return;
}

void test_str_lower()
{
    char x[MAX_BUF];
    char y[MAX_BUF];

    std::cin.getline(y, MAX_BUF);
    str_lower(x, y);

    std::cout << x << std::endl;
    return;
}

void test_str_tok()
{
    char x[MAX_BUF];
    char y[MAX_BUF];
    char delimiters[MAX_BUF];

    std::cin.getline(y, MAX_BUF);
    std::cin.getline(delimiters, MAX_BUF);
    bool b = str_tok(x, y, delimiters);

    std::cout << '{' <<  b <<  "} {" << x << "} {" << y << '}' <<  std::endl;
    return;           
}

void test_str_strip()
{
    int x = 0;
    char y[MAX_BUF];
    std::cout << '\n';
    std::cin >> x;
    
    switch(x)
    {
        case 0:
            std::cin.getline(y, MAX_BUF);
            std::cout << '|' << y << '|' << std::endl;
            str_lstrip(y);
            break;
        case 1:
            std::cin.getline(y, MAX_BUF);
            std::cout << '|' << y << '|' << std::endl;
            str_rstrip(y);
            break;
        case 2:
            std::cin.getline(y, MAX_BUF);
            std::cout << '|' << y << '|' << std::endl;
            str_strip(y);
            break;
    }
    std::cout << '|' << y << '|' << std::endl;
    
}

int main()
{
    // while(1)
    // {
    //     char s[MAX_BUF];
    //     std::cin.getline(s, MAX_BUF);
    //     if(std::cin.eof()) break;
    //     if(std::cin.fail() || std::cin.bad())
    //     {
    //         std::cin.clear();
    //         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //     }
    //     else
    //     {
    //         std::cout << '[' << s << "]\n";
    //         for (int i = 0; i < str_len(s); ++i)
    //         {
    //             std::cout << i << ' ' << s[i] << ' ' << int(s[i]) << std::endl;
    //         }
    //     }
    // }

    int i = 0;
    std::cin >> i;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (i)
    {
        case 0:
            test_str_cmp();
            break;
        case 1:
            test_str_cpy();
            break;
        case 2:
            test_str_chr();
            break;
        case 3:
            test_str_str();
            break;
        case 4:
            test_str_lower();
            break;
        case 5:
            test_str_tok();
            break;
        case 6:
            test_str_strip();
            break;
    }
    
    return 0;
}
