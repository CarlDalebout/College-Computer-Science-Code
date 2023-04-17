#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

template< typename S, typename T>
std::ostream & operator<<(std::ostream & cout,
                          std::unordered_map< S, T > & v)
{
    std::string delim= "";
    cout << '{';
    for(auto & x: v)
    {
        cout << delim << x.first
             << ':'
             << x.second
            ; delim = ", ";
    }
    cout << '}';
    return cout;
}

template< typename S, typename T>
std::ostream & operator<<(std::ostream & cout,
                          std::unordered_map< S, T > & v)
{
    std::string delim= "";
    cout << '{';
    for(auto & x: v)
    {
        cout << delim
             << x.first
             << ':'
             << x.second
            ; delim = ", ";
    }
    cout << '}';
    return cout;
}
int main ()
{
 
    std::vector< int > v{1, 3, 5, 2, 4};
    std::cout << v << '\n';
    v.push_back(42);
    std::cout << v << '\n';
    auto p = v.begin();
    ++p;
    v.erase(p);
    std::cout << v << '\n';


    std::unordered_set< int >X;
    for (auto & x:std::vector< int >(1, 3, 5))
    {
        X.insert(x);
        std::cout << X << '\n';
    }
    if (X.find(7) == X.end())// not found
    {
        std::cout << "7 is not found\n";
    }
    if (X.find(3) == X.end())// not found
    {
        std::cout << "3 is found\n";
    }

    std::unordered_map<int,int> h;
    for (auto & x:std::vector< int >(1, 3, 5))
    {
        h[x] = 2 *x;
        std::cout << X << '\n';
    }
    return 0;
}
