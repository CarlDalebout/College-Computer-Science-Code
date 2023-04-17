#include <iostream>
#include <cmath>
#include "vec2d.h"



bool vec2d::operator==(const vec2d & v) const
{
    return (x_ == v.x_ && y_ == v.y_);
}
bool vec2d::operator!=(const vec2d & v) const
{
    return !operator==(v);
}


double vec2d::x() const
{
    return x_;
}
double & vec2d::x()
{
    return x_;
}

double vec2d::y() const
{
    return y_;
}
double & vec2d::y()
{
    return y_;
}


double vec2d::operator[](int v) const
{
    if(v == 0)
        return x_;
    else if( v == 1)
        return y_;
    else
    {
        std::cout << "The number that was input is out of scope return -1.0\n";
        exit(0);
    }
}
double & vec2d::operator[](int v)
{
    if(v == 0)
        return x_;
    else if( v == 1)
        return y_;
    else
    {
        std::cout << "The number that was input is out of scope return -1.0\n";
        exit(0);
    }
}


vec2d vec2d::operator+() const
{
    vec2d ret(x_, y_);
    return ret;
}

vec2d vec2d::operator-() const
{
    vec2d ret(x_ * -1, y_ * -1);
    return ret;    
}

vec2d vec2d::operator+(const vec2d & v) const
{
    vec2d ret(x_ + v.x_, y_ + v.y_);
    return ret;
}
vec2d vec2d::operator-(const vec2d & v) const
{
    return operator+(-v);
}
vec2d vec2d::operator*(double v) const
{
    vec2d ret(x_ * v, y_ * v);
    return ret;
}
vec2d vec2d::operator/(double v) const
{
    vec2d ret(x_ / v, y_ / v);
    return ret;
}


vec2d & vec2d::operator+=(const vec2d & v)
{
    *this = *this + v; 
    return *this;
}
vec2d & vec2d::operator-=(const vec2d & v)
{
    *this = *this - v;
    return *this;
}
vec2d & vec2d::operator*=(double v)
{
    *this = *this * v;
    return *this;
}
vec2d & vec2d::operator/=(double v) 
{
    *this = *this / v;
    return *this;
}

vec2d operator*(double v, const vec2d & u)
{
    vec2d ret(u.x() * v, u.y() * v);
    return ret;
}

double len(const vec2d & v)
{
    double ret = sqrt(v.x() * v.x() + v.y() * v.y());
    return ret;
}

double dotpro(const vec2d & u, const vec2d & v)
{
    double ret = (u.x() * v.x()) + (u.y() * v.y());
    return ret;
}

vec2d norm(const vec2d & v)
{
    double Len = len(v);
    vec2d ret(v.x()/Len, v.y()/Len);
    return ret;
}

std::ostream & operator<<(std::ostream & cout, const vec2d & v)
{
    cout << '{'  <<v.x() << ", " << v.y() << '}';
    return cout;
}

std::istream & operator>>(std::istream & cin, vec2d & v)
{
    double x,y;
    cin >> v.x() >> v.y();


    return cin;
}
