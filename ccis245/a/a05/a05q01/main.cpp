#include <iostream>
#include <cstdlib>
#include "Robot.h"

void test_print()
{
    char name;
    int x,y;
    int energylevel;
    std::cin >> name >> x >> y >> energylevel;
    Robot r;
    init(r, name, x, y, energylevel);
    print(r);
    return;
}

int main()
{
    int seed;
    std::cin >> seed;
    srand(seed);

    int option = 0;
    std::cin >> option;

    switch (option)
    {
        case 0:
            test_print();
            break;
    }
    
    return 0;
}
