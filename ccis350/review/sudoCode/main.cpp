#include <iostream>

int main()
{
    int n;
    std::cin >> n;
    int s = 0;
    int i = 1
    
    Loop::if(i >= n+1)
    goto EXIT;
    s = s + i;
    i = i + 1;
    goto Loop;
    EXIT::return 0;
}