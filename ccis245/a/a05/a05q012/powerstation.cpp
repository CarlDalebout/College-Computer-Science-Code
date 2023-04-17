/***************************************************************************

File  : powerstation.cpp
Author: Carl Dalebout

Implementation of functions prototypes in powerstation.h




***************************************************************************/
#include <iostream>
#include "powerstation.h"
#include "world.h"
#include "Robot.h"


void init(PowerStation & p, int x, int y, int energylevel)
{
    p.x = x;
    p.y = y;
    p.energylevel = energylevel;
}

void init(PowerStation &p, char world[10][10])
{
    int x, y;
    while (1)
    {
        x = rand() % 10;
        y = rand() % 10;
        //std::cout << "trying:" << x << ',' << y << '\n';
        if(is_unoccupied(world, x, y))
        {
            init(p, x, y, 50);
            set(world, x, y, 'P');
            break;
        }    
    }
}

void charge_robot(PowerStation & p, Robot * r)
{
    int n = 0;

    for(int i = 0; i < 3; i++)
    {
        if(p == r[i])
            n++;
    }

    for(int i = 0; i < 3; i++)
    {
        if(p.energylevel >= n * 10)
        {
            if(p == r[i])
                r[i].energylevel += 10;
            
        }

        else
        {
            if(p == r[i])
                r[i].energylevel += p.energylevel/n;
        }
    }

    if(p.energylevel >= n * 10)
        p.energylevel-= n * 10;
    else
        p.energylevel -= n * (p.energylevel/n);
    
}

bool operator==(PowerStation & p , Robot & r)
{
    //north
    if(p.y-1 == r.y && p.x == r.x)
        return true;

    //south
    else if(p.y+1 == r.y && p.x == r.x)
        return true;

    //east
    else if(p.y == r.y && p.x+1 == r.x)
        return true;

    //west
    else if(p.y == r.y && p.x-1 == r.x)
        return true;

    // not found
    else
        return false;
}
