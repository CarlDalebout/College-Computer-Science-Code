#include <iostream>

bool isUgly(int n) {
    while(1)
    {
        if(n == 0)
        {
            return 0;
        }
        else if(n % 2 == 0)
        {
            n /= 2;
            std::cout << n << '\n';
        }
        else if(n % 3 == 0)
        {
            n /= 3;
            std::cout << n << '\n';
        }
        else if(n % 5 == 0)
        {
            n /= 5;
            std::cout << n << '\n';
        }
        else if(n == 1)
        {
            return true;
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    int x;
    std::cin >> x;
    std::cout << isUgly(x) << '\n';
}