#ifndef ROBOT_H
#define ROBOT_H

struct Robot
{
    char name;
    int x, y;
    int energylevel;
};

void init(Robot &, char name, int x, int y, int energylevel);

void init(Robot &,char name, char world[10][10]);

inline
void print(const Robot & robot)
{
    std::cout << "<Robot: name=" << robot.name
         << ", x=" << robot.x
         << ", y=" << robot.y
         << ", energylevel=" << robot.energylevel
         << ">\n";
}

void move_north(Robot & robot);

void move_south(Robot & robot);

void move_east(Robot & robot);

void move_west(Robot & robot);

void move_rand(Robot & robot, char world[10][10]);

inline
void inc_energylevel(Robot & robot, int d)
{
    robot.energylevel += d;
}

inline
void dec_energylevel(Robot & robot, int d)
{
    robot.energylevel -= d;
}

#endif
