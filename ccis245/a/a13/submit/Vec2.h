#ifndef VEC2_H
#define VEC2_H

template < typename T>
class Vec2
{
public:
    Vec2()
        :x_((int)0), y_((int)0)
    {}
    Vec2(T x, T y)
        :x_(x), y_(y)
    {}
    
    bool operator==(const Vec2<T> &) const;
    bool operator!=(const Vec2<T> &) const;

    T  x() const;
    T &x();
    
    T  y() const;
    T &y();

    T  operator[](int) const;
    T &operator[](int);

    Vec2<T> operator+() const;
    Vec2<T> operator-() const;

    Vec2<T> operator+(const Vec2<T> &) const;
    Vec2<T> operator-(const Vec2<T> &) const;
    Vec2<T> operator*(T) const;
    Vec2<T> operator/(T) const;
    
    Vec2<T> & operator+=(const Vec2<T> &);
    Vec2<T> & operator-=(const Vec2<T> &);
    Vec2<T> & operator*=(T);
    Vec2<T> & operator/=(T);

    
private:
    T x_, y_;
};

template < typename T >
bool Vec2<T>::operator==(const Vec2<T> & v) const
{
    return (x_ == v.x_ && y_ == v.y_);
}

template < typename T >
bool Vec2<T>::operator!=(const Vec2<T> & v) const
{
    return !operator==(v);
}

template < typename T >
T Vec2<T>::x() const
{
    return x_;
}
template < typename T >
T & Vec2<T>::x()
{
    return x_;
}

template < typename T >
T Vec2<T>::y() const
{
    return y_;
}
template < typename T >
T & Vec2<T>::y()
{
    return y_;
}

template < typename T>
T Vec2<T>::operator[](int v) const
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
template < typename T >
T & Vec2<T>::operator[](int v)
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

template< typename T >
Vec2<T> Vec2<T>::operator+() const
{
    Vec2<T> ret(x_, y_);
    return ret;
}

template < typename T >
Vec2<T> Vec2<T>::operator-() const
{
    Vec2<T> ret(x_ * -1, y_ * -1);
    return ret;    
}

template < typename T >
Vec2<T> Vec2<T>::operator+(const Vec2<T> & v) const
{
    Vec2<T> ret(x_ + v.x_, y_ + v.y_);
    return ret;
}

template < typename T >
Vec2<T> Vec2<T>::operator-(const Vec2<T> & v) const
{
    return operator+(-v);
}

template < typename T >
Vec2<T> Vec2<T>::operator*(T v) const
{
    Vec2<T> ret(x_ * v, y_ * v);
    return ret;
}

template < typename T >
Vec2<T> Vec2<T>::operator/(T v) const
{
    Vec2<T> ret(x_ / v, y_ / v);
    return ret;
}

template < typename T >
Vec2<T> & Vec2<T>::operator+=(const Vec2<T> & v)
{
    *this = *this + v; 
    return *this;
}

template < typename T >
Vec2<T> & Vec2<T>::operator-=(const Vec2<T> & v)
{
    *this = *this - v;
    return *this;
}

template < typename T >
Vec2<T> & Vec2<T>::operator*=(T v)
{
    *this = *this * v;
    return *this;
}

template < typename T >
Vec2<T> & Vec2<T>::operator/=(T v) 
{
    *this = *this / v;
    return *this;
}

template < typename T >
Vec2<T> operator*(T v, const Vec2<T> & u)
{
    Vec2<T> ret(u.x() * v, u.y() * v);
    return ret;
}

template < typename T >
T len(const Vec2<T> & v)
{
    T ret = sqrt(v.x() * v.x() + v.y() * v.y());
    return ret;
}

template < typename T >
T dotpro(const Vec2<T> & u, const Vec2<T> & v)
{
    T ret = (u.x() * v.x()) + (u.y() * v.y());
    return ret;
}

template < typename T>
Vec2<T> norm(const Vec2<T> & v)
{
    T Len = len(v);
    Vec2<T> ret(v.x()/Len, v.y()/Len);
    return ret;
}

template < typename T >
std::ostream & operator<<(std::ostream & cout, const Vec2<T> & v)
{
    cout << '{'  << v.x() << ", " << v.y() << '}';
    return cout;
}

template < typename T >
std::istream & operator>>(std::istream & cin, Vec2<T> & v)
{
    T x,y;
    cin >> v.x() >> v.y();
    return cin;
}


// template < typename T>
// Vec2<T> operator+ (const Vec2<T> &);

// template < typename T >
// Vec2<T>  operator*(T, const Vec2<T> &);

// template < typename T >
// T len(const Vec2<T> &);

// template < typename T >
// T dotpro(const Vec2<T> &, const Vec2<T> &);

// template < typename T >
// Vec2<T>  norm(const Vec2<T> &);

// template < typename T >
// std::ostream & operator<<<T>(std::ostream &, const Vec2< T > &);

// template < typename T>
// std::istream & operator>><T>(std::istream &, Vec2< T > &);

#endif
