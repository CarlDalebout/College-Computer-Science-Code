// Name: Carl Dalebout
// File: main.cpp

#include <iostream>

void swap(int *p, int *q)
{
    int t;

     t = *p;
    *p = *q;
    *q = t;
    
}


void bubblesort(int *x, int *begin, int *end)
{
    int *p = begin;
    int *q = begin;

    while(p < end - 1)
    {
        q = begin;
        while(q < end - 1)
        {
            if(*q > *(q+1))
                swap(q,(q+1));
            q++;
        }
        p++;
    }
    
}


void println(int *x, int *begin, int *end)
{
    int *p = begin;
    std::cout << '{';
    while(p<end - 1)
    {
        std::cout << *p << ", "; 
        p = p + 1;
    }
    
    std::cout << *p << "}\n";
}


int main()
{
    int x[1024];
    int n;
    std::cin >> n;
    for(int i = 0; i<n; ++i)
    {
        std::cin >> x[i];
    }
    std::cout << x[n] << '\n';
    println(x, &x[0], &x[n]);

    bubblesort(x, &x[0], &x[n]);
    println(x, &x[0], &x[n]);
    
    return 0;
}
