#include<iostream>
#include "Fraction.h"

void Fraction_print(int n, int d)
{
    if(n==d)
    {
        std::cout<<'1';
    }
    else if(n==0)
    {
        std::cout<<'0';
    }
    else if(d==0)
    {
        std::cout<<"undefined";
    }
    else
    {
        reduce(n,d);
    }
    if(d==1)
        std::cout<<n;
    else
        std::cout<<n<<'/'<<d;
}

void Fraction_add(int xn, int xd,
                  int yn, int yd,
                  int& zn, int& zd)
{
    zn = xn*yd + yn*xd;
    zd = xd*yd;
}

void Fraction_sub(int xn, int xd,
                  int yn, int yd,
                  int& zn, int& zd)
{
    zn = xn*yd -  yn*xd;
    zd = xd*yd;
}

void Fraction_mult(int xn, int xd,
                   int yn, int yd,
                   int &zn, int &zd)
{
    zn = xn * yn;
    zd = xd * yd;
}

void Fraction_div(int xn, int xd,
                  int yn, int yd,
                  int &zn, int &zd)
{
    zn = xn * yd;
    zd = xd * yn;
}

void Fraction_addeq(int &xn, int &xd,
                     int yn, int yd)
{
    xn = xn*yd + yn*xd;
    xd *= yd;
}

void Fraction_multeq(int &xn, int &xd,
                     int yn, int yd)
{
    xn = xn*yn;
    xd = xd*yd;
}

bool Fraction_eq(int xn, int xd, int yn, int yd)
{
    reduce(xn,xd);
    reduce(yn,yd);   
    if(xn == yn && xd == yd)
        return 1;
    else
        return 0;
}

bool Fraction_neq(int xn, int xd, int yn, int yd)
{
    reduce(xn,xd);
    reduce(yn,yd);   
    if(xn == yn && xd == yd)
        return 0;
    else
        return 1;
}

bool Fraction_lt(int xn, int xd, int yn, int yd)
{

    double x = (double)xn/ (double)xd;
    double y = (double)yn/ (double)yd;

    if(x<y)
        return 1;
    else
        return  0;
}
void reduce(int &n, int &d)
{
    if(n<0 && d<0)
    {
        n *= -1;
        d *= -1;
    }
    else if(n<0 || d<0)
    {
        if(d<0)
        {
            n *= -1;
            d *= -1;
            // std::cout<<"swapped the negative to n\n";
            
        }
        else{}
    }
    
    int gcd = findgcd(n,d);

    if(gcd < 0)
    {
        gcd *= -1;
    }

    if( gcd > 0){
        n /= gcd;
        d /= gcd;
    }
    else{}   
}

int findgcd(int m, int n)
{
    if (n == 0)
        return m;
    else
        return findgcd(n, m % n);
}
