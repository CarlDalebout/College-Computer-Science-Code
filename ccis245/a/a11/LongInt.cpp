#include <iostream>
#include <string>
#include <cmath>
#include "LongInt.h"

void LongInt::reduce()
{
    for(int i = 0; i < v_.size(); ++i)
    {
        int carry = v_[i]/10;
        if(v_[i] >9)
        {
            v_[i] -= carry * 10;
            if(i+1 >= v_.size())
                v_.push_back(carry);
            else
                v_[i+1] += carry;
        }
        else if(v_[i] < 0)
        {
            v_[i] += 10;
            if(i+1 >= v_.size())
                v_.push_back(-1);
            else
                v_[i+1] -= 1;
        }
    }
}

LongInt & LongInt::operator=(const LongInt & x)
{
    sign_ = x.sign();
    int N = x.size();
    for(unsigned int i = 0; i < N; ++i)
    {
        if(i >= v_.size())
            v_.push_back(x[i]);
        else
            v_[i] = x[i];
    }
    return *this;
}

bool LongInt::operator==(LongInt & x) const
{
    if(v_.size() != x.size()) return false;
    for(unsigned int i = 0; i <= v_.size(); ++i)
        if(v_[i] != x[i]) return false;
    return true;
}

bool LongInt::operator!=(LongInt & x) const  
{return !(*this == x);}

bool LongInt::operator> (LongInt & x) const  
{
    return false;
    // if(sign_ < x.sign()) return false;
    // else if(*this - x < 0) return false;
    // else return true;
}
bool LongInt::operator>=(LongInt & x) const  
{
    if(operator==(x)) return true;
    return (operator>(x));
}

bool LongInt::operator< (LongInt & x) const  
{
    return !(*this > x);
}
bool LongInt::operator<=(LongInt & x) const  
{
    if(*this == x) return true;
    return (*this < x);
}

//with two LongInt Objects
LongInt &LongInt::operator+=(const LongInt & x)
{
    if(v_.size() < x.size())
    {
        LongInt temp(*this);
        *this = x;
        return (*this += temp);
    }
    
    for(int i = 0; i < v_.size(); ++i)
    {
        if(sign_ == x.sign() && i < x.size())
            v_[i] += x[i];
        else if(sign_ != x.sign() && i < x.size())
            v_[i] -= x[i];
        
        //std::cout << i << ' ' << *this << '\n';
        reduce();
    }
    
    if(v_.size() == 0)
    {}
    else if(v_[v_.size()-1] == -1 )
    {
        sign_ *= -1;
        v_.resize(v_.size()-1);
        for(int i = v_.size()-1; i > 0; --i)
        {
            v_[i] = (v_[i] - 9) * -1;
        }
        v_[0] = (v_[0] -10) * -1;
    }
    return *this;
}

LongInt LongInt::operator+ (const LongInt & x) 
{
    LongInt ret(*this);
    return ret += x;
}

LongInt &LongInt::operator-=(const LongInt & x)
{
    LongInt ret(x);
    ret.sign() *= -1;
    return(*this += ret);
}

LongInt LongInt::operator- (const LongInt & x)
{
    LongInt ret(*this);
    return ret.operator-=(x);
}

LongInt &LongInt::operator*=(const LongInt & x)
{
    if(v_.size() > x.size())
    {
        LongInt temp(*this);
        *this = x;
        return (*this *= temp);
    }
    
    LongInt ret;
    for(int i = 0; i < v_.size(); ++i)
    {
        for(int j = 0; j < x.size(); ++j)
        {
            ret += (v_[i] * std::pow(10,i) * sign_) * (x[j] * std::pow(10,j) *x.sign());
        }

    }
    *this = ret;
    return *this;
}

LongInt LongInt::operator* (const LongInt & x)
{
    LongInt ret(*this);
    ret *= x;
    return ret;
}

LongInt &LongInt::operator+=(const int x)
{
    LongInt temp(x);
    return operator+=(temp);
}
    
// //with int on the right
// LongInt operator+(const LongInt & i, int j)
// {
//     LongInt temp = get_LongInt(j);
//     return (i + temp);
// }
// LongInt operator-(const LongInt & i, int j)
// {
//     LongInt temp = get_LongInt(j);
//     return (i - temp);
// }

// //with int on the left
// LongInt operator+(int i, const LongInt & j)
// {
//     LongInt temp = get_LongInt(i);
//     return (temp + j);
// }
// LongInt operator-(int i, const LongInt & j)
// {
//     LongInt temp = get_LongInt(i);
//     return (temp - j);
// }


std::ostream & operator<<(std::ostream & cout, const LongInt & x)
{
    if(x.sign() == -1) cout << '-';
    int i = x.size()-1;
    while(x[i] == 0) --i; // checks for 000111  115 5 1 1
    std::string dir = "";
    cout << '<';
    for(i = i; i >= 0; --i)
    {
        cout << dir << x[i]; dir = ", "; 
    }
    cout << '>';
    return cout;
}

std::istream & operator>>(std::istream & cin, LongInt & I)
{
    return cin;
}
