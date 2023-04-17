#include <iostream>
#include "fraction.h"

int findgcd(int n, int d)
{
    if (d == 0)
        return n;
    else
        return findgcd(d, n % d);
}

void reduce(Fraction & f0)
{
    if(f0.n<0 && f0.d<0)
    {
        f0.n *= -1;
        f0.d *= -1;
    }
    else if(f0.n<0 ||f0.d<0)
    {
        if(f0.d<0)
        {
            f0.n *= -1;
            f0.d *= -1;            
        }
        else{}
    }

    
    int gcd = findgcd(f0.n,f0.d);

    if(gcd < 0)
    {
        gcd *= -1;
    }

    if( gcd > 0){
        f0.n /= gcd;
        f0.d /= gcd;
    }
    else{}  
}

Fraction operator+(Fraction & f0, Fraction & f1)
{
    Fraction ret = {f0.n * f1.d + f1.n * f0.d, f0.d * f1.d};
    return ret;
}

std::ostream & operator<<(std::ostream & cout, Fraction & f0)
{
    if(f0.n==f0.d)
    {
        cout <<'1';
    }
    else if(f0.n==0)
    {
        cout<< "0";
    }
    else if(f0.d==0)
    {
        cout<<"undefined";
    }
    else
    {
        reduce(f0);
        
        if(f0.d==1)
            cout<<f0.n;
        else
            cout<< '{' << f0.n << '/' << f0.d << '}';
    }
    return cout;
}

