#include <iostream>
#include <thread>
#include <string>

void print()
{
    int i = 0;
    for(;; ++i)
    {
        if(i == 100000000)
        {
            std::cout << '.' ;
            i = 0;
        }
    }

}

void input()
{
    std::string s;
    for(;;)
    {
        std::getline(std::cin, s);
        std::cout << "Thank you for your input";
    }
}

int main()
{
    std::thread th1(print);
    std::thread th2(input);
    th1.join();
    th2.join();
    
    return 0;
}