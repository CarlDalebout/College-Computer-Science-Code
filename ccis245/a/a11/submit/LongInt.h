#ifndef LONGINT_H
#define LONGINT_H

#include <iostream>
#include <string>
#include <vector>

class LongInt
{
public:
    LongInt(int x = 0)
    {
        if(x < 0){sign_ = -1; x *= -1;}
        else sign_ = 1;
        int i = 0;
        while(x != 0)
        {
            v_.push_back(x % 10); 
            x /= 10;
            i++;
        }
    }

    LongInt(const char x[])
    {
        int i = 0;
        int len = 0;
        while(x[len] != '\0') ++len;
        if(x[i] == '-')
        {
            sign_ = -1;
            ++i;
        }
        else if(x[i] == '+')
        {
            ++i;
        }
        for(len -= i; len >= 1; --len)
        {
            v_.push_back(x[len]-48);
        }
    }

    LongInt(const LongInt &x)
    {
        for(unsigned int i = 0; i < x.size(); ++i)
        {
            v_.push_back(x[i]);
        }
        sign_ = x.sign_;
    }

    int  size() const {return v_.size();}
    int  sign() const {return sign_;}
    int &sign() {return sign_;}

    void reduce();

    int operator[](int i) const {return v_[i];}

    LongInt &operator=(const LongInt &);
    
//bool operators
    bool operator==(LongInt &) const;
    bool operator!=(LongInt &) const;
    bool operator> (LongInt &) const;
    bool operator>=(LongInt &) const;
    bool operator< (LongInt &) const;
    bool operator<=(LongInt &) const;
    
    
//with two LongInt Objects
    LongInt &operator+=(const LongInt &);
    LongInt  operator+ (const LongInt &);
    LongInt &operator-=(const LongInt &);
    LongInt  operator- (const LongInt &);
    LongInt &operator*=(const LongInt &);
    LongInt  operator* (const LongInt &);
    LongInt &operator/=(const LongInt &);
    LongInt  operator/ (const LongInt &);

    
//with int on the right
    LongInt &operator+=(const int);
    LongInt  operator+ (const int);
    LongInt &operator-=(const int);
    LongInt  operator- (const int);
    LongInt &operator*=(const int);
    LongInt  operator* (const int);
    LongInt &operator/=(const int);
    LongInt  operator/ (const int);
    
    
private:
    std::vector<int> v_;
    int sign_;
    
};

//with int on the left
    LongInt operator+ (const int, const LongInt &);
    LongInt operator- (const int, const LongInt &);
    LongInt operator* (const int, const LongInt &);
    LongInt operator/ (const int, const LongInt &);
    

std::ostream & operator<<(std::ostream &, const LongInt &);
std::istream & operator>>(std::istream &, LongInt &);

#endif
