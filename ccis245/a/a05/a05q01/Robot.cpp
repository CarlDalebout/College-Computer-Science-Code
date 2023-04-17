/***************************************************************************

File  : Robot.cpp
Author: smaug

Implementation of functions prototypes in Robot.h.




***************************************************************************/
#include <iostream>
#include "Robot.h"

void init(Robot & r, char name, int x, int y, int energylevel)
{
    r.name = name;
    r.x = x;
    r.y = y;
    r.energylevel = energylevel;
}


void print(const Robot & robot)
{
    std::cout << "<Robot: name=" << robot.name
         << ", x=" << robot.x
         << ", y=" << robot.y
         << ", energylevel=" << robot.energylevel
         << ">'\n";
}

void move_north(Robot & robot)
{
    robot.y++;
}

void move_south(Robot & robot)
{
    robot.y--;
}

void move_east(Robot & robot)
{
    robot.x++;
}

void move_west(Robot & robot)
{
    robot.x--;
}

void inc_energylevel(Robot & robot, int d)
{
    robot.energylevel += d;
}

void dec_energylevel(Robot & robot, int d)
{
    robot.energylevel -= d;
}

