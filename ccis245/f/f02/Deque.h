// File Name: Deque.h
// Author: Carl Dalebout

#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <cstddef>

const int MAX_CAPACITY = 100;

class UnderflowError{};

class OverflowError{};

template < typename T>
class Deque
{
public:
    Deque()
        :x_(NULL), size_(0), capacity_(0)
    {}
    Deque(int size)
        :x_(new T[size]),
         size_(size), capacity_(size)
    {}
    Deque(Deque & dq)
        :x_(new T[dq.size_]),
         size_(dq.size_), capacity_(dq.size_)
    {
        for(int i = 0; i < size_; ++i)
        {
            x_[i] = dq.x_[i];
        }
    }
    ~Deque()
    {
        delete[] x_;
    }

    int size()     { return size_; }
    int capacity() { return capacity_;}

    void resize(int);
    
    void insert_head(T);
    T remove_head();

    void insert_tail(T);
    T remove_tail();

    void clear();
    bool is_empty();

    Deque<T> & operator= (const Deque<T> & dq); 
    
//private:
    T   *x_;
    int  size_;
    int  capacity_;
};

template <typename T>
void Deque<T>::resize(int size)
{

     if(size <= capacity_)
    {
        size_ = size;
    }
    else
    {
        T *g = new T[size];
        for(int i = 0; i < size_; ++i)
        {
            g[i] = x_[i];
            //std::cout << "coping " << x_[i] << " into g " << i << '\n';
        }
        delete[] x_;
        x_ = g;
        capacity_ = size;
        size_ = size;
    }
}

template <typename T>
void Deque<T>::insert_head(T value)
{
    if(size_ >= MAX_CAPACITY)
        throw OverflowError();
    resize(size_ + 1);
    for(int i = size_ - 1; i > 0; --i)
        x_[i] = x_[i-1];
    x_[0] = value;
}

template <typename T>
T Deque<T>::remove_head()
{
    T ret = x_[0];
    if(size_ == 0)
        throw UnderflowError();
    else
    {
        for(int i = 0; i < size_ - 1; ++i)
        {
            x_[i] = x_[i+1];
        }
        resize(size_ -1);
    }
    return ret;
}

template <typename T>
void Deque<T>::insert_tail(T value)
{
    if(size_ >= MAX_CAPACITY)
        throw OverflowError();
    resize(size_ + 1);
    x_[size_-1] = value;
}

template <typename T>
T Deque<T>::remove_tail()
{
    if(size_ == 0)
        throw UnderflowError();
    resize(size_ - 1);
    return x_[size_];
}

template <typename T>
void Deque<T>::clear()                                 
{
    resize(0);
}

template <typename T>
bool Deque<T>::is_empty()
{
    if(size_ == 0)
        return true;
    return false;
}

template <typename T>
Deque<T> & Deque<T>::operator= (const Deque<T> & dq)
{
    if(capacity_ <= dq.size_)
        resize(dq.size_);
    for(int i = 0; i < dq.size_; ++i)
    {
        x_[i] = dq.x_[i];
    }

    return *this;
}

template < typename T >
std::ostream & operator<<(std::ostream & cout, const Deque<T> & dq)
{
    std::string dir = "";
    cout << '[';
    for(int i = 0; i < dq.size_; ++i)
    {
        cout << dir << dq.x_[i]; dir = ", ";
    }
    cout << ']';
    return cout;
}

#endif
