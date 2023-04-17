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

template < typename T >
class Comparator
{

    bool operator()(T x, T y) { return (x < y);}
    

};


void sort(array & array)
{
    for(int i = array.n; i > 0; --i)
    {
        for(int j = 0; j < i-1; ++j)
        {
            if(array.x[j+1] < array.x[j]) 
            {
                int t = array.x[j+1];
                array.x[j+1] = array.x[j];
                array.x[j] = t;
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
        sort(array);

        std::cout << array << '\n';

        delete[] array.x;
    }
    return 0;
}