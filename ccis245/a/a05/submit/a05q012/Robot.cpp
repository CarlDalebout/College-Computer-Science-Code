/***************************************************************************

File  : Robot.cpp
Author: smaug

Implementation of functions prototypes in Robot.h.




***************************************************************************/
#include <iostream>
#include "Robot.h"
#include "world.h"

void init(Robot & r, char name, int x, int y, int energylevel)
{
    r.name = name;
    r.x = x;
    r.y = y;
    r.energylevel = energylevel;
}

void init(Robot & r,char name, char world[10][10])
{
    int x, y;
    while(1)
    {
        x = rand() % 10;
        y = rand() % 10;
        //std::cout << "trying:" << x << ',' << y << '\n';
        if(is_unoccupied(world, x ,y))
        {
            init(r, name, x, y , 100);
            set(world, x, y, name);
            break;
        }
    }
}

void move_north(Robot & robot)
{
    if(robot.energylevel != 0)
    {
        robot.y--;
        robot.energylevel--;
    }
}

void move_south(Robot & robot)
{
    if(robot.energylevel != 0)
    {
        robot.y++;
        robot.energylevel--;
    }
}

void move_east(Robot & robot)
{
    if(robot.energylevel != 0)
    {
        robot.x++;
        robot.energylevel--;
    }
}

void move_west(Robot & robot)
{
    if(robot.energylevel != 0)
    {
        robot.x--;
        robot.energylevel--;
    }
}

void move_rand(Robot & r, char world[10][10])
{
    int d = rand() % 4;

    switch(d)
    {
        case 0:
            if(r.y == 0 || is_occupied(world, r.x, r.y - 1))
                break;
            else
            {
                clear(world, r.x, r.y);
                set(world, r.x, r.y-1, r.name);
                move_north(r);
            }
            break;

        case 1:
            if(r.y == 9 || is_occupied(world, r.x, r.y + 1))
                break;
            else
            {
                clear(world, r.x, r.y);
                set(world, r.x, r.y+1, r.name);
                move_south(r);
            }
            break;

        case 2:
            if(r.x == 9 || is_occupied(world, r.x + 1, r.y))
                break;
            else
            {
                clear(world, r.x, r.y);
                set(world, r.x+1, r.y, r.name);
                move_east(r);
            }
            break;

        case 3:
            if(r.x == 0 || is_occupied(world, r.x - 1, r.y))
                break;
            else
            {
                clear(world, r.x, r.y);
                set(world, r.x-1, r.y, r.name);
                move_west(r);
            }
            break;
    };
}
