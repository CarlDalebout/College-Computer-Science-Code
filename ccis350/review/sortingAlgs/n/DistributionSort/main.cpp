#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <string>

void print(int * s, int * e)
{
    std::cout << '[';
    std::string  dir = "";
    for(int* i = s; i < e; ++i)
    {
        std::cout << dir << *i; dir = ", ";
    }
    std::cout << "]\n";
}

void DistributionSort(int * s, int * e, int m)
{
    int* t = new int[m];
    for(int* i = s; i < e; ++i)
    {
        t[*i]++;
    }
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < t[i]; ++j)
        {
            *(s+i+j) = i;
        }
    }
    delete[] t;

}

int main()
{
    srand(time(NULL));
    int n = 20;
    int x[n]; 
    for(int i = 0; i < n; ++i)
    {
        x[i] = rand()%100;
    }
    print(&x[0],&x[n]);
    DistributionSort(&x[0], &x[n], 100);
    print(&x[0],&x[n]);

    return 0;
}