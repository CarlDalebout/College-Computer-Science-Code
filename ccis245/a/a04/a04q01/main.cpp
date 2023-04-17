// Name: Carl Dalebout
// File main.cpp

#include <iostream>

void scanf(int *);
void scanf(char *);
void scanf(double *);

int main()
{
    char c = 0;
    int i =0;
    double d = 0;
    scanf(&c);
    scanf(&i);
    scanf(&d);
    std::cout << c << std::endl;
    std::cout << i << std::endl;
    std::cout << d << std::endl;

    return 0;
}

void scanf(int *i)
{
    scanf("%d", i);
}

void scanf(char *c)
{
    scanf("%c", c);
}

void scanf(double *d)
{
    scanf("%lf", d);
}
