//File: IntDynArr.h
//Author: Carl Dalebout

#ifndef INTDYNARR_H
#define INTDYNARR_H

#include <iostream>

class IntDynArr
{
public:
    IntDynArr(int N = 0)
        :x_(new int[N]), size_(0), capacity_(N)
    {
        if(x_ == NULL)
        {
            std::cout << "ERROR!!! You ran out of member!!!";
            exit(0);
        }
    }
    IntDynArr(int N, int a[])
        :x_(new int[N]), size_(N) , capacity_(N)
    {
        if(x_ == NULL)
        {
            std::cout << "ERROR!!! You ran out of member!!!";
            exit(0);
        }
        for(int i = 0; i < N; ++i)
        {
            x_[i] = a[i];
        }
    }
    IntDynArr(const IntDynArr & a)
        :x_(new int[a.get_size()]), size_(a.get_size()), capacity_(a.get_size())
    {
        for(int i = 0; i < size_; ++i)
        {
            x_[i] = a[i];
        }
    }
    ~IntDynArr()
    {
        delete[] x_;
    }

    int get_size() const { return size_; }

    void resize(const int);

    int get_capacity() const { return capacity_;}

    int operator[](int i) const { return x_[i]; }
    int & operator[](int i) { return x_[i]; }
    
    bool operator==(const IntDynArr &);
    bool operator!=(const IntDynArr &);

    IntDynArr & operator+=(const IntDynArr &);
    IntDynArr   operator+ (const IntDynArr &);

    IntDynArr & operator=(const IntDynArr &);

    IntDynArr & insert(int, int);
    IntDynArr & remove(int);

    IntDynArr subarray(int, int length = -1) const;

    void print();

    
private:
    int *x_;
    int size_;
    int capacity_;
};

std::ostream & operator<<(std::ostream &, const IntDynArr &);
std::istream & operator>>(std::istream &, IntDynArr &);
#endif
