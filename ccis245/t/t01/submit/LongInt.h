#ifndef LONGINT_H
#define LONGINT_H

#include <iostream>
#include <string>

struct LongInt
{
    int x_[1000];
    int size_ = 0;
    int sign_ = 1;
    
};

int str_len(const char s[]);

LongInt get_LongInt(const char s[]);
LongInt get_LongInt(const int);

//bool operators
bool operator==(const LongInt &, const LongInt &);
bool operator!=(const LongInt &, const LongInt &);
bool operator> (const LongInt &, const LongInt &);
bool operator>=(const LongInt &, const LongInt &);
bool operator< (const LongInt &, const LongInt &);
bool operator<=(const LongInt &, const LongInt &);


//with two LongInt Objects
LongInt operator+(const LongInt &, const LongInt &);
LongInt operator-(const LongInt &, const LongInt &);
LongInt operator*(const LongInt &, const LongInt &);
LongInt operator/(const LongInt &, const LongInt &);

//with int on the right
LongInt operator+(const LongInt &, int);
LongInt operator-(const LongInt &, int);
LongInt operator*(const LongInt &, int);
LongInt operator/(const LongInt &, int);


//with int on the left
LongInt operator+(int, const LongInt &);
LongInt operator-(int, const LongInt &);
LongInt operator*(int, const LongInt &);
LongInt operator/(int, const LongInt &);


std::ostream & operator<<(std::ostream &, const LongInt &);
std::istream & operator>>(std::istream &, LongInt &);
#endif
