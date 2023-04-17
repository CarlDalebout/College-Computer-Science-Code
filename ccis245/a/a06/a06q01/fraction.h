#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

struct Fraction
{
    int n;
    int d;
};

int findgcd(int, int);

void reduce(Fraction &);

Fraction operator+(Fraction &, Fraction &);

std::ostream & operator<<(std::ostream & , Fraction &);
    
#endif
