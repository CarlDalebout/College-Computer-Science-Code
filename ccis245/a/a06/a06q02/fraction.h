#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

struct Fraction
{
    int n;
    int d;
};

int findgcd(int, int);

void  reduce( Fraction &);

//void operator = (Fraction &);

Fraction operator + (const Fraction &, const Fraction &);

std::ostream & operator << (std::ostream & ,const Fraction &);
    
#endif
