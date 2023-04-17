#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <string>

/*
    Quicksort Ideas
        1) pivit Selection
            picking a value inside of an array. 
                3 pivot selection all
                    1) pick first value (in the textbook)
                    2) randomly pick a value within the array (n = end - start), (pick = rand() % n + start)
                    *3) median-of-3 (mid = start + (end - start)/2) sort the start mid and end value  
        2) partition (used for many other algs) 
            preforms and partition after you pick a pivit (p)
                1) the left side of the pivit must be <= p and the right must be >p
                2) recall quicksort on the left and right side of the array  p = &2 |5|3|0|1|2| -> |1|0|2|5|3|
*/


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

int * partition(int * s, int * e, int* p)
{   
    int * i = s;
    int * j = s;
    int t = *p;
    for(int* k = p; k > s; --k)
    {
        *k = *(k-1);
    }
    *s = t;
    while(j < e)
    {
        print(s, e+1);
        int distance_i = ((3*(i-s))+2);
        int distance_j = ((3*(j-s))+2);
        std::cout << std::setw(distance_i) << "i" << '\n';
        std::cout << std::setw(distance_j) << "j" << '\n';
        
        if(*i >= *(i + 1))
        {
            t = *i;
            *i = *(i+1);
            *(i+1) = t;
            i = i + 1;
            if(j < i)
                j = j + 1;
        }
        else if(*(j+1) > *i)
        {
            j = j + 1;
        }
        else if(*(j+1) <= *i)
        {
            int t = *(i+1);
            *(i+1) = *(j+1);
            *(j+1) = t;
        }
    }

    return i;
}

int* pivotSelection(int * s, int *e)
{
    int* p  = s + (e-s)/2;
    //std:: cout << "s " << *s << " p " <<*p<< " e " << *e << '\n';

    // 5 2 3 | 2 5 3 | 5 3 2 | 3 5 2 | 2 3 5 | 3 2 5        
    // 2 5 3 | 2 5 3 | 3 5 2 | 3 5 2 | 2 3 5 | 2 3 5  
    // 2 3 5 | 2 3 5 | 3 2 5 | 3 2 5 | 2 3 5 | 2 3 5
    // 2 3 5 | 2 3 5 | 2 3 5 | 2 3 5 | 2 3 5 | 2 3 5
    if(*s > *p)
    {
        int t = *s; *s = *p; *p = t;
    }
    if(*p > *e)
    {
        int t = *p; *p = *e; *e = t; 
    }
    if(*s > *p)
    {
        int t = *s; *s = *p; *p = t;
    }
    return p;
}

void quickSort(int * s, int * e)
{

    if(e-s <= 3)
    {
        if(e-s == 3)
        {
            pivotSelection(s, e);
        }
        else if(e-s == 2)
        {
            if(*s > *(e-1))
            {
                int t = *s;
                *s = *(e-1);
                *(e-1) = t;
            }
        }

    }
    else
    {
        int* pivot_index =pivotSelection(s, e);
        pivot_index = partition(s, e, pivot_index);
        quickSort(s,pivot_index);
        quickSort(pivot_index+1 , e);
    }

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
    // int* pivot_index = pivotSelection(&x[0], &x[n-1]);
    // print(&x[0], &x[n]);
    // std::cout << "the pivot point is " << *pivot_index << '\n'; 

    // pivot_index = partition(&x[0], &x[n-1], pivot_index);
    quickSort(&x[0], &x[n-1]);
    print(&x[0], &x[n]);
    return 0;
}