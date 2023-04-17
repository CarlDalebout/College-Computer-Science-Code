#include <iostream>
#include <cstdlib>
#include "Robot.h"
#include "world.h"
#include "powerstation.h"
#include "Gold.h"

int main()
{
    int seed;
    std::cin >> seed;
    srand(seed);
    char world[10][10];
    init(world);

    PowerStation p[3];

    for(int i = 0; i < 3; i++)
    {
        init (p[i], world);
    }

    Robot r[3];

    init(r[0], 'c', world);
    init(r[1], 'r', world);
    init(r[2], 'd', world);

    Gold g;

    init(g, world);

    int time = 100;
    int direction = 0;
        
    while (time > 0)
    {
        if(found(g,world))
            break;

        for(int i = 0; i < 3; i++)
        {
            move_rand(r[i], world);
        }

        for(int i = 0; i < 3; i++)
        {
            charge_robot(p[i], &r[0]);            
        }

        std::cout << "Time: " << time << '\n';
        print(world);
        for(int i =0; i < 3; i++)
        {
            print(r[i]);
        }
        for(int i =0; i < 3; i++)
        {
            print(p[i]);
        }
        print(g);
        --time;
    }
    
    
    return 0;
}
