#ifndef FRACTION_H
#define FRACTION_H

void Fraction_print(int, int);

int *getn();

int *getd();

void Fraction_add(int, int, int, int, int &, int &); // add fraction xn/xd and yn/yd to zn/zd

void Fraction_sub(int, int, int, int, int &, int &);

void Fraction_mult(int, int, int, int, int &,int &);

void Fraction_div(int, int, int, int, int &,int &);

void Fraction_addeq(int &, int &, int, int);

void Fraction_multeq(int &, int &, int, int);

bool Fraction_eq(int, int, int, int);

bool Fraction_neq(int, int, int, int);

bool Fraction_lt(int, int, int, int);

void reduce(int &,int &);

int findgcd(int,int);

#endif // FRACTION_H
