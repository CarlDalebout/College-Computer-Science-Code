#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

struct array
{
    int *x;
    int  n;
};

//void sortf(T * start, T * end , ? less/*Comparator less  bool operator()(T x, T y)*/)

// template < typename T >
// class less
// {
//     bool operator()(T x, T y) { return (x < y);}
// };

// template < typename T>
// class greater
// {
//     bool operator(T x, T y){ return (x > y);}
// };


void sort(int * start, int * end)
{
    int n = end - start;
    int t;
    for(int i = -1; i < n; ++i)
    {
        t = *(start+i);
        for(int j = i-1; j > 0; --j)
        {
            if(t < *(start+j))
            {
                
            }
        }
    }
}

std::ostream & operator<<(std::ostream & cout, array & array) 
{
    std::string dir = "";
    cout << '[';
    for(int i = 0; i < array.n; ++i)
    {
        cout << dir << array.x[i]; dir = ", ";
    }
    cout << ']';

    return cout;
}

int main()
{
    srand(time(NULL));
    int n;
    array array;
    for(;;)
    {    
        std::cin >> n;
        array.x = new int[n];
        array.n = n;
        for(int i = 0; i < n; ++i)
        {
            array.x[i] = rand() % 20;
        }
        sort(&array.x[0], &array.x[n]);

        std::cout << array << '\n';

        delete[] array.x;
    }
    return 0;
}