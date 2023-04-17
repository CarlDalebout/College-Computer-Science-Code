#include <iostream>
#include "Rational.h"

int GCD(int n, int d)
{
    if (d == 0)
        return n;
    else
        return GCD(d, n % d);
}

int sign(int v)
{

    return v;
}


void Rational::reduce()
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
    
    int gcd = GCD(n,d);

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

bool Rational::operator==(const Rational & r) const
{
    Rational test1 = { n, d };
    Rational test2 = { r.n, r.d };
    test1.reduce();
    test2.reduce();

    return(test1.n == test2.n && test1.d == test2.d);
}

bool Rational::operator!=(const Rational & r) const
{
    return !operator==(r);
}

bool Rational::operator> (const Rational & r) const
{
    Rational test1 = { n, d };
    Rational test2 = { r.n, r.d };

    return (test1.n * test2.d > test1.d * test2.n);
}

bool Rational::operator>=(const Rational & r) const
{
    Rational test1 = { n, d };
    Rational test2 = { r.n, r.d };
    
    return (test1.n * test2.d >= test1.d * test2.n);
}

bool Rational::operator< (const Rational & r) const
{
    Rational test1 = { n, d };
    Rational test2 = { r.n, r.d };

    return(test1.n * test2.d < test1.d * test2.n);
}

bool Rational::operator<=(const Rational & r) const
{
    Rational test1 = { n, d };
    Rational test2 = { r.n, r.d };

    return (test1.n * test2.d <= test1.d * test2.n);
}


Rational & Rational::operator+=(const Rational & r)
{
    n = (n * r.d) + (r.n * d);
    d = d * r.d;
    this->reduce();

    return *this;
}

Rational & Rational::operator-=(const Rational & r)
{
    n = (n * r.d) - (r.n * d);
    d = d * r.d;
    this->reduce();

    return *this;
}

Rational & Rational::operator*=(const Rational & r)
{
    n = n * r.n;
    d = d * r.d;
    this->reduce();

    return *this;
}

Rational & Rational::operator/=(const Rational & r)
{
    n = n * r.d;
    d = d * r.n;
    this->reduce();

    return *this;
}

Rational Rational::operator+() const
{
    return *this;
}

Rational Rational::operator-() const
{
    Rational test = { -n, d };
    return test;
}

Rational Rational::operator+(const Rational & r) const
{
    Rational temp ((n * r.d + r.n * d), d* r.d);
    
    temp.reduce();

    return temp;
}

Rational Rational::operator-(const Rational & r) const
{
    Rational temp (n * r.d - r.n * d, d* r.d);
    
    temp.reduce();

    return temp;
}

Rational Rational::operator*(const Rational & r) const
{
    Rational temp (n * r.n, d * r.d);
    
    temp.reduce();

    return temp;
}

Rational Rational::operator/(const Rational & r) const
{
    Rational temp (n * r.d, d * r.n);
    
    temp.reduce();

    return temp;
}

Rational Rational::abs() const
{
    Rational test = { n, d };
    test.reduce();
    if(test.n < 0) test.n *= -1;

    return test;
}

Rational Rational::pow(int v) const
{
    Rational test = { n, d };

    for(int i = 1; i < v; ++i)
    {
        test.n *= n;
        test.d *= d;
    }

    std::cout << "test after loop: " << test << '\n';

    test.reduce();

    return test;
}

int Rational::get_int() const
{
    return (n / d);
}

double Rational::get_double() const
{
    return ((double)n / (double)d);
}

std::ostream & operator<<(std::ostream & cout, const Rational & r)
{
    if(r.get_d() == 1 )
    {
        cout << '{' << r.get_n() << '}';
    }
    else
    {
        cout << '{' << r.get_n() << ", " << r.get_d() << "}";
    }
    return cout;
}

std::istream & operator>>(std::istream & cin, Rational & r)
{
    int n, d;
    cin >> n >> d;
    
    r.set_n(n);
    r.set_d(d);
    
    return cin;
}

void reduce(Rational & r)
{
    r.reduce();
}

Rational abs(const Rational & r)
{
    return r.abs();
}

Rational pow(const Rational & r, int v)
{
    return r.pow(v);
}


bool operator==(int v, const Rational & r)
{
    Rational test = {r.get_n(), r.get_d()};

    test.reduce();

    return (test.get_d() == 1 && test.get_n() == v);
}

bool operator!=(int v, const Rational & r)
{
    return !operator==(v, r);
}

bool operator> (int v, const Rational & r)
{ 
    Rational test = { r.get_n(), r.get_d() };
    test.reduce();
    return ( v > test.get_n() / test.get_d() );
}

bool operator>=(int v, const Rational & r)
{
    Rational test = { r.get_n(), r.get_d() };
    test.reduce();
    return ( v >= test.get_n() / test.get_d() );
}

bool operator< (int v, const Rational & r)
{
    Rational test = { r.get_n(), r.get_d() };
    test.reduce();
    return ( v < test.get_n() / test.get_d() );
}

bool operator<=(int v, const Rational & r)
{
    Rational test = { r.get_n(), r.get_d() };
    test.reduce();
    return ( v <= test.get_n() / test.get_d() );
}


int & operator+=(int & v, const Rational & r)
{
    v = (v + (r.get_n() / r.get_d()));
    return v;
}

int & operator-=(int & v, const Rational & r)
{
    v = (v - (r.get_n() / r.get_d()));
    return v;
}

int & operator*=(int & v, const Rational & r)
{
    v = ((v * r.get_n()) / r.get_d());
    return v;
}

int & operator/=(int & v, const Rational & r)
{
    v = ((v * r.get_d()) / r.get_n());
    return v;
}

Rational operator+(int v, const Rational & r)
{
    return v += r;
}

Rational operator-(int v, const Rational & r)
{
    return v -= r;
}

Rational operator*(int v, const Rational & r)
{
    return v *= r;
}

Rational operator/(int v, const Rational & r)
{
    return v /= r;
}
