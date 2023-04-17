#ifndef FIB2_H
#define FIB2_H

class Fib2
{
public:
    Fib2()
        : t(new int[20])
    {
        t[0] = t[1] = 1;
    }
    ~Fib2()
    {
        delete[] t;
    }
    int operator()(const int);
    int operator[](const int i) {return t[i];}
    

private:
    int *t;
};

#endif
