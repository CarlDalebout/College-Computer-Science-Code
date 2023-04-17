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
    cout << "<Rotot: name = " << robot.name
         << ", x=" << robot.x
         << ", y=" << robot.y
         << ", energylevel=" << robot.energylevel
         << ">'\n";
}

