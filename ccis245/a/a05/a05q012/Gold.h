#ifndef GOLD_H
#define GOLD_H

struct Gold
{
    int x, y;
};

void init(Gold & g, int x, int y);

void init(Gold & g, char world[10][10]);

bool found(Gold & g, char world[10][10]);

inline
void print(Gold & g)
{
    std::cout << "<Gold: y=" << g.y
              << ", x=" << g.x
              << ">\n";
}

#endif
