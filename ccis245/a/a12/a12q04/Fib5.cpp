#include <iostream>
#include <string>
#include "Fib5.h"

int* Fib5::t_(NULL);
int  Fib5::size_(0);
int  Fib5::numb_objects_(0);

void Fib5::resize(const int n)
{
    if(Fib5::t_ == NULL)
    {
        Fib5::t_ = new int [2];
        t_[0] = t_[1] = 1;
        Fib5::size_ = 2;
    }
    int *temp = new int [n+1];
    
    for(int i = 0; i <= n; ++i)
    {
        if(i < Fib5::size())
            temp[i] = t_[i];
        else
            temp[i] = -1;
    }
    
    delete[] t_;
    Fib5::t_ = temp;
    Fib5::size_ = n + 1;
    
}

int Fib5::lookup(const int i)
{
    if(i >= Fib5::size_)
        Fib5::resize(i);
    return t_[i];
}

int& Fib5::set(const int i)
{
    if(i > Fib5::size_)
      Fib5:resize(i);
    return t_[i];
    
}

int Fib5::operator()(const int i)
{
    if(i > 0)
    {
        if (i >= Fib5::size_)
            resize(i);
        if(lookup(i) == -1)
            set(i) = (operator()(i-1) + operator()(i - 2));

        return lookup(i);
    }
    return 1;
}

std::ostream & operator<<(std::ostream & cout, const Fib5 & fib4)
{
    std::string dir = "";
    cout << '<';
    for(int i = 0; i < Fib5::size(); ++i)
    {
        cout << dir << Fib5::lookup(i); dir = ", ";
    }
    cout << '>';
    return cout;
}
