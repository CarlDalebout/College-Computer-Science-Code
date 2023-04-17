#include <iostream>

int max_rec(int x[], int start, int end)
{   
    int ret;
    if (start == end-1)
    {
        ret = x[start];
        std::cout << "max_rec(x, " << start << ", " << end << ") base case ..." << "return " << ret << '\n';
        return ret;
    }
    else
    {
        std::cout << "max_rec(x, " << start << ", " << end << ") recursive case ...\n";
        int y = max_rec(x, start, end-1); 
        if(x[end] < y)
        {
            ret = y;    
            std::cout << "max_rec(x, " << start << ", " << end << ") recursive case ..." << "return " << ret << '\n';
            return ret;
        }
        else
        {
            ret = x[end];
            std::cout << "max_rec(x, " << start << ", " << end << ") recursive case ..." << "return " << ret << '\n';
            return ret;
        }
    }
}
int main()
{
    int n;   
    std::cin >> n;
    int * x = new int[n];
    
    for (int i = 0; i < n; ++i)
    {
        std::cin >> x[i];
    }
    
    int max = max_rec(x, 0, n);
    std::cout << max << '\n';
    
    delete [] x;
    return 0;
}

// 0 n = 1
//(0)< 2 n = 2
//(0 < 2) < 3 n = 3
//(0 < 2 < 3) < 4  n = 4