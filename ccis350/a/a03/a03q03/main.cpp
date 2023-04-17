#include <iostream>
int linearsearch_rec(int x[], int start, int end, int target)
{
    int ret
    if (start+1 == end)
    {
        ret = -1;
        std::cout << "linearsearch_rec(x, " << start << ", " << end << ", "
        << target << ") base case ..."
        << "return " << ret << '\n';
        return ret;
    }
    else
    {
        std::cout << "linearsearch_rec(x, " << start << ", " << end << ", "
        << target << ") recursive case ...\n";
        int y = linearsearch_rec(x, start+1, end, target);
        if(x[start] == target)
        {
            ret = y;
            std::cout << "linersearch_rec(x," << start << ", " << end<< ", " << target << ") recursive case ..." << "return " << ret << '\n';
            return ret;
        }
        else
        {

        }
    }
}

int main()
{
    int n, target;
    std::cin >> n;
    int * x = new int[n];
    for (int i = 0; i < n; ++i)
    {
        std::cin >> x[i];
    }
    std::cin >> target;
    int index = linearsearch_rec(x, 0, n, target);
    std::cout << index << '\n';
    delete [] x;
    return 0;
}