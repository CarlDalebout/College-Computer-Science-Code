#include <iostream>
#include "Deque.h"

int main()
{
    Deque <int> dq;
    std::cout << dq << std::endl;
    dq.insert_head(5);
    std::cout << dq << std::endl;
    dq.insert_head(6);
    std::cout << dq << std::endl;
    dq.insert_tail(-1);
    std::cout << dq << std::endl;
    std::cout << dq.size() << std::endl;

    Deque< int > dq1(dq);
    std::cout << dq1 << std::endl;
    Deque< int > dq2;
    dq2 = dq; std::cout << dq2 << std::endl;
    dq  = dq; std::cout << dq << std::endl;

    int head = dq.remove_head();
    std::cout << head << ' ' << dq << dq.size() << std::endl;
    int tail = dq.remove_tail();
    std::cout << tail << ' ' << dq << dq.size() << std::endl;

    dq.clear();
    std::cout << dq << std::endl << dq.is_empty() << std::endl;
    
    try
    {
        dq.remove_head();
    }
    catch(UnderflowError & e)
    {
        std::cout << "Underflow error!" << std::endl;
    }

    try
    {
        while(1)
            dq.insert_tail(1);
    }
    catch(const OverflowError & e)
    {
        std::cout << "overflow error!!" << std::endl;
    }
    return 0;
}
