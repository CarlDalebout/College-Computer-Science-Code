//File Mystring.h
//Author: Carl Dalebout

#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>

class Mystring
{
public:
    Mystring(const char s[] = "")
        :size_(0), cap_(1024)
    {
        
        while(s[size_] != '\0')
        {
            x_[size_] = s[size_];
            size_++;
        }
        x_[size_] = '\0';
    }
    Mystring(char s)
        : x_{s}, size_(1), cap_(1024)
    {}
    Mystring(int N, char s)
        :size_(N), cap_(1024)
    {
        for(int i = 0; i<N; ++i)
        {
            x_[i] = s;
        }
    }
    Mystring(const Mystring & y)
        :size_(y.size_), cap_(1024)
    {
        for(int i = 0; i < size_; ++i)
        {
            x_[i] = y[i];
        }
    }
    
    char operator[](int) const;
    char & operator[](int);

    int  size()const;
    int &size();
    int  cap()const;
    int  find(char c, int start = 0);
    int  find(Mystring y, int start = 0);
    void resize(int);
    void resize(int, char);
    Mystring & clear();

    Mystring substr(int, int)const;

    Mystring & operator= (const Mystring &);
    Mystring & operator= (const char []);
    Mystring & operator+=(const Mystring &);
    Mystring & operator+=(const char);
    Mystring   operator+ (const Mystring &);
    Mystring   operator+ (const char);
    bool operator==(const Mystring &);
    bool operator==(const char);
    bool operator==(const char []);

    bool operator!=(const Mystring & y) {return !(*this == y);}
    
private:
    char x_[1024];
    int size_;
    const int cap_;
};

std::ostream & operator<<(std::ostream &, const Mystring &);
std::istream & operator>>(std::istream &, Mystring &);

#endif
