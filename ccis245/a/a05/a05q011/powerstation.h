#ifndef POWERSTATION_H
#define POWERSTATION_H

struct PowerStation
{
    int x, y;
    int energylevel;
};

void init(PowerStation & powerstation, int x, int y, int energylevel);

inline
void print(const PowerStation & powerstation)
{
    std::cout << "<Powerstation: x=" << powerstation.x << ", y=" << powerstation.y << ", energylevel=" << powerstation.energylevel << ">\n";
}

inline
void dec_energylevel(PowerStation & powerstation, int d)
{
    powerstation.energylevel -= d;
}

#endif
