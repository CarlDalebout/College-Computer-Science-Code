/******************************************************************************
File  : vec2d.h
Author: Carl Dalebout
Date  : 10/24/2022
******************************************************************************/

#ifndef VEC2D_H
#define VEC2D_H

#include <iostream>

class vec2d
{
  public:
    vec2d(double x = 0, double y = 0)
        : x_(x), y_(y)
    {}

    bool operator==(const vec2d &) const;
    bool operator!=(const vec2d &) const;

    double x() const;
    double & x();
    
    double y() const;
    double & y();

    double operator[](int) const;
    double & operator[](int);

    vec2d operator+() const;
    vec2d operator-() const;

    vec2d operator+(const vec2d &) const;
    vec2d operator-(const vec2d &) const;
    vec2d operator*(double) const;
    vec2d operator/(double) const;
    
    vec2d & operator+=(const vec2d &);
    vec2d & operator-=(const vec2d &);
    vec2d & operator*=(double);
    vec2d & operator/=(double);
    

private:
    double x_, y_;
};

vec2d  operator*(double, const vec2d&);
double len(const vec2d &);
double dotpro(const vec2d &, const vec2d &);
vec2d  norm(const vec2d &);
std::ostream & operator<<(std::ostream &, const vec2d &);
std::istream & operator>>(std::istream &, vec2d &);

#endif
