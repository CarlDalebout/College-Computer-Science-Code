#ifndef POWERSTATION_H
#define POWERSTATION_H
#include "Robot.h"

struct PowerStation
{
    int x, y;
    int energylevel;
    
};

void init(PowerStation & powerstation, int x, int y, int energylevel);

void init(PowerStation & p, char world[10][10]);

inline
void print(const PowerStation & powerstation)
{
    std::cout << "<Powerstation: x=" << powerstation.x
              << ", y=" << powerstation.y
              << ", energylevel=" << powerstation.energylevel
              << ">\n";
}

inline
void dec_energylevel(PowerStation & powerstation, int d)
{
    powerstation.energylevel -= d;
}

void charge_robot(PowerStation & p, Robot * r);

bool operator==(PowerStation & p, Robot & r);

#endif
