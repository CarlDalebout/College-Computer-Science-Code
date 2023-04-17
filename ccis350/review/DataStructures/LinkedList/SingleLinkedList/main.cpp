#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "SLNode.h"
#include "SLList.h"



int main()
{
    srand(time(NULL));
    SLNode * n5 = new SLNode(5);
    SLNode * n3 = new SLNode(3);
    SLNode * n1 = new SLNode(1);
    SLNode * n0 = new SLNode(0);

    n5->next(n3);
    n3->next(n1);
    n1->next(n0);

    // std::cout << (*n5) << '\n';
    // std::cout << (*n3) << '\n';
    // std::cout << (*n1) << '\n';
    // std::cout << (*n0) << '\n';

    SLNode * p = n5;
    
    while(p != NULL)
    {   
        std::cout << (*p) << '\n';
        p = p->next_;
    }

    SLList list;
    for(int i = 0; i < 5; ++i)
    {
        list.insertH(i);
    }
    for(int i = 0; i < 6; ++i)
    {
        list.deleteH();
    }

    std::cout << '\n' << list << '\n';
    // std::cout << (*n5) << '\n';
    
    delete n5;
    delete n3;
    delete n1;
    delete n0;
    return 0;
}