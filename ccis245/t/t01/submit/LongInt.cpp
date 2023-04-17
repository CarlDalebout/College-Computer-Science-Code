#include <iostream>
#include <string>
#include "LongInt.h"

int str_len(const char s[])
{
    int len = 0;
    while (s[len] != '\0') ++len;
    return len;
}

LongInt get_LongInt(const char s[])
{
    LongInt ret;
    int s_size = str_len(s);
    // std::cout << "size of s is " << s_size << '\n';

    if(s[0] != '-')
    {
        int i = 0 ,j= 0;
        if(s[0] == '+') ++i;
        while(s[i] == '0')
        {
            i++;
        }
           
        ret.size_ = s_size - i;
        
        for(i = 0; i <= ret.size_; ++i)
        {            
            ret.x_[i] = s[s_size - i - 1] - 48;
        }
    }
    else
    {
        int i = 1;
        ret.sign_ = -1;
        while(s[i] == '0')
        {
            i++;
        }
           
        ret.size_ = s_size - i;
        
        for(i = 0; i <= ret.size_; ++i)
        {            
            ret.x_[i] = s[s_size - i - 1] - 48;
        }
    }
    
    return ret;
}

LongInt get_LongInt(const int s)
{
    LongInt ret;
    int temp = s;
    int i = 0;
    // std::cout << "size of s is " << s_size << '\n';
    if (temp < 0) ret.sign_ = -1;
    while(temp != 0)
    {
        ret.x_[i] = temp % 10;
        temp /= 10;
        ++i;
    }
    ret.size_ = i;
    
    return ret;
}

bool operator==(const LongInt & l0, const LongInt & l1)
{
    if(l0.size_ != l1.size_) return false;

    for(int i = 0; i <= l0.size_; ++i)
    {
        if(l0.x_[i] != l1.x_[i]) return false;
    }

    return true;
}
bool operator!=(const LongInt & l0, const LongInt & l1)  
{
    return !(l0 == l1);
}
bool operator> (const LongInt & l0, const LongInt & l1)  
{
    if(l0.sign_ < l1.sign_) return false;
    for(int i = 0; i < l0.size_; ++i)
    {
        if(l0.x_[i] < l1.x_[i]) return false;
    }

    return true;
}
bool operator>=(const LongInt & l0, const LongInt & l1)  
{
    if(l0 == l1) return true;
    return (l0 > l1);
}
bool operator< (const LongInt & l0, const LongInt & l1)  
{
    return !(l0 > l1);
}
bool operator<=(const LongInt & l0, const LongInt & l1)  
{
    if(l0 == l1) return true;
    return (l0 < l1);
}

//with two LongInt Objects
LongInt operator+(const LongInt & I , const LongInt & J)
{
    LongInt ret;
    
    ret.x_[0] = 0;
    
        if(I.sign_ == J.sign_)
        {
            if(I.sign_ == -1)
                ret.sign_ = -1;
            int i = 0;
            bool carry = false;
            
            while(i <=I.size_ || i <=J.size_)
            {

                if(i < I.size_ && i < J.size_)
                {
                    //std::cout << "1)" << ret.x_[i] << '+' <<  I.x_[i] << '+' << J.x_[i];

                    ret.x_[i] =  I.x_[i] + J.x_[i] + ret.x_[i];

                    //std::cout << '=' << ret.x_[i] << " in " << i << '\n'; 
                }
                else if(i < I.size_)
                {
                    //std::cout << "2)" << ret.x_[i] << "+" << I.x_[i];
                    ret.x_[i] += I.x_[i];
                    //std::cout << "=" << ret.x_[i] << " in " << i << '\n';
                }
                else if(i < J.size_)
                {
                    //std::cout << "3)" << ret.x_[i] << "+" << J.x_[i];
                    ret.x_[i] += J.x_[i];
                    //std::cout << "=" << ret.x_[i] << " in " << i << '\n';
                }
                
                
                if(ret.x_[i] >= 10)
                {
                    //std::cout << "Carrying the 1" << '\n';
                    ret.x_[i] -= 10;
                    carry = true;
                }
                ++i;
                if(carry)
                {
                    ret.x_[i] = 1;
                    if(i >= I.size_ && i >= J.size_)
                        break;
                    carry = false;
                }
                else
                    ret.x_[i] = 0;
            }
            
            ret.size_ = i - 1;
            if(carry)
            {
                ret.size_++;
            }
            return ret;
        }

        else
        {
            int i = 0;
            bool carry = false;
            
            while(i <=I.size_ ||  i <=J.size_)
            {
                
                if(i < I.size_ && i < J.size_)
                {
                    //std::cout << "1)" << ret.x_[i] << '+' <<  I.x_[i] << '+' << J.x_[i];

                    ret.x_[i] =  (I.x_[i] * I.sign_) + (J.x_[i] * J.sign_) + ret.x_[i];

                    //std::cout << '=' << ret.x_[i] << " in " << i << '\n'; 
                }
                else if(i < I.size_)
                {
                    //std::cout << "2)" << ret.x_[i] << "+" << I.x_[i];
                    ret.x_[i] += (I.x_[i] * I.sign_);
                    //std::cout << "=" << ret.x_[i] << " in " << i << '\n';
                }
                else if(i < J.size_)
                {
                    //std::cout << "3)" << ret.x_[i] << "+" << J.x_[i];
                    ret.x_[i] += (J.x_[i] * J.sign_);
                    //std::cout << "=" << ret.x_[i] << " in " << i << '\n';
                }
                
                
                if(ret.x_[i] < 0)
                {
                    //std::cout << "Carrying the 1" << '\n';
                    ret.x_[i] += 10;
                    carry = true;
                }
                ++i;
                if(carry)
                {
                    ret.x_[i] = -1;
                    carry = false;
                }
                else
                    ret.x_[i] = 0;
            }
            ret.size_ = i -1;
            if(ret.x_[i] == -1)
            {
                ret.sign_ = -1;
                ret.x_[0] = -1 * (ret.x_[0] - 10);
                for(i = 1;  i < ret.size_; ++i)
                {
                    ret.x_[i] = -1 * (ret.x_[i] - 9);
                }
            }
            return ret;
        }
}

LongInt operator-(const LongInt & i , const LongInt & j)
{
    LongInt temp = j;
    temp.sign_ *= -1;
    return(i + temp);
}


//with int on the right
LongInt operator+(const LongInt & i, int j)
{
    LongInt temp = get_LongInt(j);
    return (i + temp);
}
LongInt operator-(const LongInt & i, int j)
{
    LongInt temp = get_LongInt(j);
    return (i - temp);
}

//with int on the left
LongInt operator+(int i, const LongInt & j)
{
    LongInt temp = get_LongInt(i);
    return (temp + j);
}
LongInt operator-(int i, const LongInt & j)
{
    LongInt temp = get_LongInt(i);
    return (temp - j);
}


std::ostream & operator<<(std::ostream & cout, const LongInt & I)
{
    LongInt temp = I;
    int i = 1;
    if(temp.sign_ == -1 )
    {
        cout << '-';
    }
    while(i <= temp.size_)
    {
        cout <<temp.x_[temp.size_ - i];
        ++i;
    }
    return cout;
}

std::istream & operator>>(std::istream & cin, LongInt & I)
{
    char x[1000];
    cin.getline(x, 1000);

    I = get_LongInt(x);

    return cin;
}
