#include <iostream>
#include <string>
#include "Math.h"

int* Fib::t_(NULL);
int  Fib::size_(0);
int  Fib::numb_objects_(0);
Fib  Fib::fib5;

void Fib::resize(const int n)
{
    if(Fib::t_ == NULL)
    {
        Fib::t_ = new int [2];
        t_[0] = t_[1] = 1;
        Fib::size_ = 2;
    }
    int *temp = new int [n+1];
    
    for(int i = 0; i <= n; ++i)
    {
        if(i < Fib::size())
            temp[i] = t_[i];
        else
            temp[i] = -1;
    }
    
    delete[] t_;
    Fib::t_ = temp;
    Fib::size_ = n + 1;
    
}

int Fib::lookup(const int i)
{
    if(i >= Fib::size_)
        Fib::resize(i);
    return t_[i];
}

int& Fib::set(const int i)
{
    if(i > Fib::size_)
      Fib:resize(i);
    return t_[i];
    
}

int Fib::operator()(const int i)
{
    if(i > 0)
    {
        if (i >= Fib::size_)
            resize(i);
        if(lookup(i) == -1)
            set(i) = (operator()(i-1) + operator()(i - 2));

        return lookup(i);
    }
    return 1;
}

std::ostream & operator<<(std::ostream & cout, const Fib & fib4)
{
    std::string dir = "";
    cout << '<';
    for(int i = 0; i < Fib::size(); ++i)
    {
        cout << dir << Fib::lookup(i); dir = ", ";
    }
    cout << '>';
    return cout;
}
