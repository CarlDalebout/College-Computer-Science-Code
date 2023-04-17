// Name: Carl
// File: main.cpp

#include <iostream>

void filter(int x[], int n)
{
    int * p = new int[n];

    for(int i = 0; i<n; ++i)
    {
        if( i == 0 || i == n-1) p[i] = x[i];

        else p[i] = (x[i-1] + x[i] + x[i+1])/3;
        
    }

    for(int i = 0; i<n; ++i)
    {
        x[i] = p[i];
    }
    
    delete [] p;
}

int main()
{
    int n = 0;
    std::cin >> n;
    int x[n];
    for(int i = 0; i < n; ++i)
    {
        std::cin >> x[i];
    }
    
    filter(x,n);
    
    for(int i = 0; i < n; ++i)
    {
        std::cout << x[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}
