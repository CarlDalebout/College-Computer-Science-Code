#include <iostream>
#include <string>
#include "Fib4.h"

int* Fib4::t_(NULL);
int  Fib4::size_(0);
int  Fib4::numb_objects_(0);

void Fib4::resize(const int n)
{
    if(Fib4::t_ == NULL)
    {
        Fib4::t_ = new int [2];
        t_[0] = t_[1] = 1;
        Fib4::size_ = 2;
    }
    int *temp = new int [n+1];
    
    for(int i = 0; i <= n; ++i)
    {
        if(i < Fib4::size())
            temp[i] = t_[i];
        else
            temp[i] = -1;
    }
    
    delete[] t_;
    Fib4::t_ = temp;
    Fib4::size_ = n + 1;
    
}

int Fib4::lookup(const int i)
{
    if(i >= Fib4::size_)
        Fib4::resize(i);
    return t_[i];
}

int& Fib4::set(const int i)
{
    if(i > Fib4::size_)
      Fib4:resize(i);
    return t_[i];
    
}

int Fib4::operator()(const int i)
{
    if(i > 0)
    {
        if (i >= Fib4::size_)
            resize(i);
        if(lookup(i) == -1)
            set(i) = (operator()(i-1) + operator()(i - 2));

        return lookup(i);
    }
    return 1;
}

std::ostream & operator<<(std::ostream & cout, const Fib4 & fib4)
{
    std::string dir = "";
    cout << '<';
    for(int i = 0; i < Fib4::size(); ++i)
    {
        cout << dir << Fib4::lookup(i); dir = ", ";
    }
    cout << '>';
    return cout;
}
