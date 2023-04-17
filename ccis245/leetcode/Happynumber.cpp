#include <iostream>
#include <string>
#include<bits/stdc++.h>

bool isHappy(int);

int main()
{
    int n = 0;
    std::cin>>n;
    if(isHappy(n))
        std::cout<< n << " is happy\n";
    else
        std::cout<< n << " is not happy\n";
}

bool isHappy(int n)
{
    int arry[10];
    int c = 0;
    while(n>1)
    {
        int length = log10(n)+1;
        for(int i =0; i<length; ++i)
        {
            arry[i] = n%10;
            std::cout<<"put " << n%10 << " into the array index : " << i ;
            n /= 10;
            std::cout<< "the remainder is : " << n <<'\n';
        }
        for(int i = 0; i<length; ++i)
        {
            n += arry[i]*arry[i];
            std::cout << "added " << arry[i] <<"^2\n"; 
            
        }
        std::cout<< n << " is the new number\n";
        c++;
        if(c>20)
            return false;
    }
    if(n==1)
        return true;
    else
        return false;
}
