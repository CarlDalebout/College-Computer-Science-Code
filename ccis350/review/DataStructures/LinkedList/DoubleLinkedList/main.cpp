#include <iostream>
#include "DLNode.h"
#include "DLList.h"

int main()
{
     DLList list;
    
    for(int i = 0; i < 5; ++i)
    {
        list.insertH(i);
    }
    list.insertT(-1);
    std::cout << '\n' << list << '\n';
    list.deleteH();    
    std::cout << '\n' << list << '\n';
    
    return 0;
}