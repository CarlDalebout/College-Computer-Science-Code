//File: IntDynArray.cpp
//Author: Carl Dalebout
#include <iostream>
#include <string>
#include "IntDynArr.h"

void IntDynArr::resize(const int N)
{
    if(N <= capacity_)
    {
        size_ = N;
    }
    else
    {
        //std::cout << "resizing for capacity " << capacity_*2 << '\n';
        while(N > capacity_)
        {
            if(capacity_ == 0)
                capacity_++;
            int *g = new int[capacity_*2];
            for(int i = 0; i < size_; ++i)
            {
                g[i] = x_[i];
                //std::cout << "coping " << x_[i] << " into g " << i << '\n';
            }
            
            delete[] x_;
            x_ = g;
            capacity_ *= 2;
            size_ = N;
        }
    }
}

bool IntDynArr::operator==(const IntDynArr & a)
{
    if(size_ != a.get_size())
        return false;
    for(int i = 0; i < size_; ++i)
    {
        if(x_[i] != a[i])
            return false;
    }
    return true;
}
bool IntDynArr::operator!=(const IntDynArr & a)
{
    return !operator==(a);
}

IntDynArr & IntDynArr::operator+=(const IntDynArr & a)
{
    if(capacity_ <  a.get_capacity())
        this->resize(a.get_size());
    else if(size_ < a.get_size())
        size_ = a.get_size();
    for(int i = 0; i < size_; ++i)
    {
        x_[i] += a[i];
    }
    return *this;   
}
IntDynArr IntDynArr::operator+ (const IntDynArr & a) // x.operator+(a)
{
    IntDynArr ret(size_);
    ret += *this;
    ret += a;
    return ret;
}

IntDynArr & IntDynArr::operator=(const IntDynArr & a)
{
     if(this != &a)
    {
        if(a.get_size() > capacity_)
        {
            this->resize(a.get_size());
        }
        size_ = a.size_;
        for(int i = 0; i < a.size_; ++i)
        {
            x_[i] = a[i];
        }
    }
    return *this;
}

IntDynArr & IntDynArr::insert(int index, int value)
{
    if(index > capacity_)
        this->resize(index);
    else if(size_+1 > capacity_)
        this->resize(capacity_+1);
    size_++;
    for(int i = size_; i > index; --i)
    {
        x_[i] = x_[i-1];
    }
    x_[index] = value;
    return *this;
}

IntDynArr & IntDynArr::remove(int index)
{
    for(int i = index; i < size_; ++i)
    {
        x_[i] = x_[i+1];
    }
    size_--;
    return *this;
}

IntDynArr IntDynArr::subarray(int index, int length) const
{
    IntDynArr ret(length);
    ret.size_ = length;
    for(int i = 0; i < length; ++i)
    {
        ret[i] = x_[i+index];
    }
    return ret;
}

void IntDynArr::print()
{
    std::cout << *this << ", size:" << size_
              << ", capacity:" << capacity_ << '\n';
}

std::ostream & operator<<(std::ostream & cout, const IntDynArr & x)
{
    std::string dir = "";
    cout << '[';
    for(int i = 0; i < x.get_size(); ++i)
    {
        cout << dir << x[i];
        dir = ", ";
    }
    cout << ']';
    return cout;
}

std::istream & operator>>(std::istream & cin, IntDynArr & a)
{
    int temp = 0, i = 0;
    while(1)
    {
        cin >> temp;
        if(temp == -1)
            break;
        a.resize(i+1);
        a[i] = temp;
        // std::cout << "putting " << temp << " into " << i << '\n';
        //a.print();
        ++i;
        //a.print();
    }
    return cin;
}
