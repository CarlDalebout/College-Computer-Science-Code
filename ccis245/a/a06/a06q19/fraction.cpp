#include <iostream>
#include "fraction.h"

int findgcd(int n, int d)
{
    if (d == 0)
        return n;
    else
        return findgcd(d, n % d);
}

void reduce(Fraction & temp)
{

    
    if(temp.n<0 && temp.d<0)
    {
        temp.n *= -1;
        temp.d *= -1;
    }
    else if(temp.n<0 || temp.d<0)
    {
        if(temp.d<0)
        {
            temp.n *= -1;
            temp.d *= -1;            
        }
        else{}
    }

    
    int gcd = findgcd(temp.n, temp.d);

    if(gcd < 0)
    {
        gcd *= -1;
    }

    if( gcd > 0){
        temp.n /= gcd;
        temp.d /= gcd;
    }
    else{}  
}

// void operator = (Fraction & f1)
// {
//     n = f1.n;
//     d = f1.d;
// }

Fraction operator + (const Fraction & f0, const Fraction & f1)
{
    Fraction ret = {((f0.n * f1.d) + (f1.n * f0.d)), (f0.d * f1.d)};
    //std::cout << '{' << ret.n << ", " << ret.d << "}\n";
    reduce (ret);
    return ret;
}

Fraction & operator +=  (Fraction & f0, const Fraction & f1)
{
    f0 = f0 + f1;
    //std::cout << '{' << ret.n << ", " << ret.d << "}\n";
    reduce (f0);
    return f0;
}

Fraction operator - (const Fraction & f0, const Fraction & f1)
{
    Fraction ret = {((f0.n * f1.d) - (f1.n * f0.d)), (f0.d * f1.d)};
    //std::cout << '{' << ret.n << ", " << ret.d << "}\n";
    reduce (ret);
    return ret;
}

Fraction & operator -=  (Fraction & f0, const Fraction & f1)
{
    f0 = f0 - f1;
    //std::cout << '{' << ret.n << ", " << ret.d << "}\n";
    reduce (f0);
    return f0;
}

Fraction operator * (const Fraction & f0, const Fraction & f1)
{
    Fraction ret = {f0.n * f1.n, f0.d * f1.d};
    //std::cout << '{' << ret.n << ", " << ret.d << "}\n";
    reduce (ret);
    return ret;
}

Fraction & operator *=(Fraction & f0, const Fraction & f1)
{
    f0 = f0 * f1;
    reduce(f0);
    return f0;
}

Fraction operator / (const Fraction & f0, const Fraction & f1)
{
    Fraction ret = {f0.n * f1.d, f0.d * f1.n};
    reduce(ret);
    return ret;
}

Fraction & operator /=(Fraction & f0, const Fraction & f1)
{
    f0 = f0 / f1;
    reduce(f0);
    return f0;
}

bool operator == (const Fraction & f0, const Fraction & f1)
{
    Fraction temp1 = {f0.n, f0.d};
    Fraction temp2 = {f1.n, f1.d};
    reduce(temp1);
    reduce(temp2);
    if(temp1.n == temp2.n && temp1.d == temp2.d) return true;
    else return false;      
}

bool operator != (const Fraction & f0, const Fraction & f1)
{
    Fraction temp1 = {f0.n, f0.d};
    Fraction temp2 = {f1.n, f1.d};
    reduce(temp1);
    reduce(temp2);
    if(temp1.n != temp2.n || temp1.d != temp2.d) return true;
    else return false;      
}

std::ostream & operator << (std::ostream & cout, const Fraction & f0)
{
    if(f0.n==f0.d)
    {
        cout <<"{1}";
    }
    else if(f0.n==0)
    {
        cout<< "{0}";
    }
    else if(f0.d==0)
    {
        cout<<"{undefined}";
    }
    else
    {
        Fraction temp = {f0.n, f0.d};
        reduce(temp);
        if(temp.d==1) {cout<<temp.n;}
        else {cout<< '{' << temp.n << '/' << temp.d << '}';}
    }
    return cout;
}

Fraction get_Fraction(int n, int d)
{
    Fraction f = {n, d};
    return f;    
}

int get_n(const Fraction & f)
{
    return f.n;
}

int get_d(const Fraction & f)
{
    return f.d;
}

void set_n(Fraction & f, int n)
{
    f.n = n;
}

void set_d(Fraction & f, int d)
{
    f.d = d;
}

void set(Fraction & f, int n, int d)
{
    f.n = n;
    f.d = d;
}

int get_int(Fraction  f)
{
    int ret = f.n / f.d;
    return ret;
}
    
double get_double(Fraction f)
{
    double ret = (double)f.n / (double)f.d;
    return ret;
}
