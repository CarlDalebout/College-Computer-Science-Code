#include <iostream>
#include <string>
#include "Mystring.h"

char   Mystring::operator[](int i) const
{
    return x_[i];
}

char & Mystring::operator[](int i)
{
    return x_[i];
}

int    Mystring::size()const { return size_; }

int &  Mystring::size() { return size_; }

int Mystring::cap()const { return cap_; }

int Mystring::find(char c, int start)
{
    for(int i = start; i < size_; ++i)
    {
        if(x_[i] == c)
            return i;
    }

    return -1;
}

int Mystring::find(Mystring y, int start)
{
    bool found = 0;
    for(int i = start; i < size_; ++i)
    {
        found = 1;
        for(int j = 0; j < y.size_; ++j)
        {
            if(x_[i+j] != y[j])
                found = 0;
        }
        if(found)
            return i;
    }
    return -1;
}

void Mystring::resize(int N)
{
    if( N > cap_)
    {
        std::cout << "size has gone out of scope\n";
        exit(0);
    }
    x_[N] = '\0';
    size_ = N;
}

void Mystring::resize(int N, char c)
{
    if( N > cap_)
    {
        std::cout << "size has gone out of scope\n";
        exit(0);
    }
    for(int i = size_; i < N; ++i)
    {
        x_[i] = c;
    }
    size_ = N;
    x_[N] = '\0';
}

Mystring &  Mystring::clear()
{
    
    size_ = 0;
    return *this;
}

Mystring Mystring::substr(int N, int L) const
{
    Mystring ret;
    for(int i = 0; i < L; ++i)
    {
        ret[i] = x_[N+i];
    }
    ret[L] = '\0';
    ret.size_ = L;
    return ret;
}

Mystring & Mystring::operator=(const Mystring & y)
{
    size_ = y.size_;
    for(int i = 0; i < size_; i++)
    {
        x_[i] = y.x_[i];
    }
    x_[size_] = '\0';
    return *this;
}

Mystring & Mystring::operator=(const char y[])
{
    int i = 0;
    while(y[i] != '\0')
    {
        x_[i] = y[i];
        i++;
    }
    size_ = i;
    x_[i] = '\0';
    return *this;
}

Mystring & Mystring::operator+=(const Mystring & y) //0123
{
    if(size_ + y.size_ > cap_)
    {
        std::cout << "size has gone out of scope\n";
        exit(0);
    }
    for(int i = 0; i < y.size_; i++)
    {
        x_[i+size_] = y.x_[i];
    }
    size_ += y.size_;
    x_[size_] = '\0';
    return *this;
}

Mystring & Mystring::operator+=(const char y)
{
    if(size_ + 1 > cap_)
    {
        std::cout << "size has gone out of scope\n";
        exit(0);
    }
    x_[size_] = y;
    size_++;
    x_[size_] = '\0';
    return *this;
}

Mystring   Mystring::operator+ (const Mystring & y)
{
    if(size_ + y.size_ > cap_)
    {
        std::cout << "size has gone out of scope\n";
        exit(0);
    }
    Mystring ret = *this;
    return (ret += y);
}

Mystring   Mystring::operator+ (const char y)
{
    if(size_ + 1 > cap_)
    {
        std::cout << "size has gone out of scope";
        exit(0);
    }
    Mystring ret(*this);
    return (ret += y);
}

bool Mystring::operator==(const Mystring & y)
{
    if(size_ != y.size_)
        return false;
    for(int i = 0; i < size_; ++i)
    {
        if(x_[i] != y.x_[i])
            return false;
    }
    return true;
}
bool Mystring::operator==(const char y)
{
    if(size_ > 1)
        return false;
    else if(x_[0] != y)
        return false;
    else
        return true;
}
bool Mystring::operator==(const char y[])
{
    int i = 0;
    while(y[i] != '\0')
    {
        if(i > size_)
        {
            return false;
        }
        if(x_[i] != y[i])
        {
            return false;
        }
        ++i;
    }
    return true;
    
}

std::ostream & operator<<(std::ostream & cout, const Mystring & s)
{
    std::string driv = "";
    cout << '|';
    for(int i = 0; i < s.size(); i++)
    {
        cout << driv << (char)s[i]; driv = ", ";
    }
    cout << '|';
    return cout;
}

std::istream & operator>>(std::istream & cin, Mystring & y)
{
    char s[y.cap()];
    cin.getline(s, y.cap());

    int i = 0;
    while(s[i] != '\0')
    {
        y[i] = s[i];
        ++i;
    }
    y.size() = i;
    y[i] = '\0';

    return cin;
}
