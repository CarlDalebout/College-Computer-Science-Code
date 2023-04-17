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

Fraction & operator +=(Fraction &, const Fraction &);

Fraction operator - (const Fraction &, const Fraction &);

Fraction & operator -=(Fraction &, const Fraction &);

Fraction operator * (const Fraction &, const Fraction &);

Fraction operator / (const Fraction &, const Fraction &);

bool operator == (const Fraction &, const Fraction &);

bool operator != (const Fraction &, const Fraction &);



std::ostream & operator << (std::ostream & ,const Fraction &);

Fraction get_Fraction(int, int);

int get_n(const Fraction &);

int get_d(const Fraction &);

void set_n(Fraction &, int);

void set_d(Fraction &, int);

void set(Fraction &, int, int);

int get_int(Fraction);

double get_double(Fraction);


#endif
