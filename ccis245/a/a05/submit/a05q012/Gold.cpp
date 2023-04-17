#include <iostream>
#include "Gold.h"
#include "world.h"


void init(Gold & g, int x, int y)
{
    g.x = x;
    g.y = y;
}

void init(Gold & g, char world[10][10])
{
    int x, y;
    while(1)
    {
        x = rand() % 10;
        y = rand() % 10;
        // std::cout << "trying:" << x << ',' << y << '\n';
        if(is_unoccupied(world, x, y))
        {
            init(g, x, y);
            set(world, x, y, 'G');
            break;
        }    
    }
}

bool found(Gold & g, char world[10][10])
{
    //north
    if(g.y-1 > 0 && (world[g.y-1][g.x] == 'c'
                   || world[g.y-1][g.x] == 'r'
                   || world[g.y-1][g.x] == 'd'))
    {
        //std::cout << "found N\n";
        return true;
    }
    //south
    else if(g.y+1 < 9 && (world[g.y+1][g.x] == 'c'
                        || world[g.y+1][g.x] == 'r'
                        || world[g.y+1][g.x] == 'd'))
    {
        // std::cout << "found S\n";
        return true;
    }

    //east
    else if(g.x+1 < 10 && (world[g.y][g.x+1] == 'c'
                         || world[g.y][g.x+1] == 'r'
                         || world[g.y][g.x+1] == 'd'))
    {
        //std::cout << "found E\n" << g.y << ' ' << g.x+1 << ' ' <<world[g.y][g.x+1] << '\n';
        return true;
    }

    //west
    else if(g.x-1 > 0 && ( world[g.y][g.x-1] == 'c'
                         || world[g.y][g.x-1] == 'r'
                         || world[g.y][g.x-1] == 'd'))
    {
        //std::cout << "found W\n";
        return true;
    }

    // not found
    else
        return false;
}
