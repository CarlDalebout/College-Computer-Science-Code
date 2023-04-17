// Name: Carl Dalebout
// File: main.cpp

#include <iostream>

int opendoors(int n)
{
    bool *open = new bool[n];
    bool *start = open;
    bool *end = open + n-1;
    //std:: cout << (long long) start << ' ' << (long long)end << std::endl; 
    int count = 0;

    for(int i  = 1; i < n; ++i)
    {
        if(i % 2 != 0)
        {
            for(open = start; open <=end; open += i)
            {
                *open = true;
                count++;
            }
        }
        
        else
        {
            for(open = end; open >= start; open -= i)
            {
                if(i == 0)
                    break;
                *open = false;
                count--;
            }
        }

        for(open = start; open <= end; ++open)
        {
            std::cout << *open;
        }
        std::cout << ' ' << i << std::endl;
    }

    open = start;
    end = start;
    
    delete [] open;
    return count;
}

int main()
{
    int n;
    std::cin >> n;
    std::cout << opendoors(n) << std::endl;
    return 0;
}

//n = 10
//0123456789ab
//101010111110
