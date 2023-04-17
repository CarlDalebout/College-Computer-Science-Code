#ifndef FIB3_H
#define FIB3_H

class Fib3
{
public:
   Fib3()
    {}
        
    int operator()(const int);
    static int lookup(const int i) {return t[i];}
    static int &  set(int i){return t[i];}

private:
    static int t[20];
};

#endif
