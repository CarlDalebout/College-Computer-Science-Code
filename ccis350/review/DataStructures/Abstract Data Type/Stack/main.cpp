#include <iostream>
#include <string>
#include <forward_list>

void printl(std::forward_list<int>  list)
{
    std::string dir = "";
    std::cout << '<';
    while(!list.empty())
    {
        std::cout << dir << list.front(); dir = ", ";
        list.pop_front();
    }
    std::cout << ">\n";
}

void flip(std::forward_list<int> & list)
{
    
}


int main()
{
    int x;
    std::cin >> x;
    std::forward_list<int> list;   
    while(x > 0)
    {
        list.push_front(x%10);
        x /= 10;
    }
    printl(list);

}