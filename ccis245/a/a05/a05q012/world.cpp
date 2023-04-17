/*********************************************************************

File  : world.cpp
Author:

Implementation of world.h.

*********************************************************************/
#include <iostream>
#include <cstdlib>
#include "world.h"

void init(char world[10][10])
{

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            world[i][j] = ' ';
        }
    }
    int x, y, d;
    bool placed1 = 0 , placed2 = 0;

    while(!placed1 || !placed2)
    {
        y = rand()%10;
        x = rand()%10;
        d = rand()%4;
        // std::cout << "trying " << y << ' ' << x << ' ' << d <<'\n';
        
        switch (d)
        {
            case 0: //north y-
                //std::cout << "running case 0\n";
                for(int i = 0; i < 4; ++i)
                {
                    if(y < 3)
                    {
                        break;
                    }
                    else if(is_occupied(world,x,y-i))
                    {
                        for(int j = 0; j <= i; ++j)
                            clear(world,y-i+j,x); 
                        break; 
                    }
                    else
                    {
                        if( i == 3)
                        {
                            if(!placed1) placed1 = 1;
                            else if(!placed2) placed2 = 2;
                        }
                        world[y-i][x] = 'X';
                    }                    
                }
                break;

            case 1: //south y+
                //std::cout << "running case 1\n";
                for(int i = 0; i < 4; ++i)
                {
                   if(y > 6)
                    {
                        break;
                    }
                    else if(is_occupied(world,x,y+i))
                    {
                        for(int j = 0; j <= i; ++j)
                            clear(world,y+i-j,x); 
                        break; 
                    }
                    else
                    {
                        if( i == 3)
                        {
                            if(!placed1) placed1 = 1;
                            else if(!placed2) placed2 = 2;
                        }
                        world[y+i][x] = 'X';
                    } 
                }
                break;
                
            case 2: // east x+
                //std::cout << "running case 2\n";
                for(int i = 0; i < 4; ++i)
                {
                    if(x > 6)
                    {
                        for(int j = 0; j <= i; ++j)
                            clear(world,y,x+i-j);
                        break;
                    }
                    else if(is_occupied(world,x+i,y))
                    {
                        for(int j = 0; j <= i; ++j)
                            clear(world,y,x+i-j); 
                        break; 
                    }
                    else
                    {
                        if( i == 3)
                        {
                            if(!placed1) placed1 = 1;
                            else if(!placed2) placed2 = 2;
                        }
                        world[y][x+i] = 'X';
                    }
                }
                break;
            case 3: // west x-
                //std::cout << "running case 3\n";
                for(int i = 0; i < 4; ++i)
                {
                    if(x < 3)
                    {
                        for(int j = 0; j <= i; ++j)
                            clear(world,y,x-i+j);
                        break;
                    }
                    else if(is_occupied(world,x-i,y))
                    {
                        for(int j = 0; j <= i; ++j)
                            clear(world,y,x-i+j); 
                        break; 
                    }
                    else
                    {
                        if( i == 3)
                        {
                            if(!placed1) placed1 = 1;
                            else if(!placed2) placed2 = 1;
                        }
                        world[y][x - i] = 'X';
                    }
                }
                break;
        };

        //std::cout << "placed walls " << placed1 << ' ' << placed2 << '\n';
    }
    
}

void print(char world[10][10])
{
    std::cout << "   0123456789\n  XXXXXXXXXXXX\n";

    for(int i = 0; i < 10; i++)
    {
        std::cout << i << " X";
        for (int j = 0; j < 10 ; j++)
        {
            std::cout << world[i][j];
        }
        std::cout << "X\n";
    }

    std::cout << "  XXXXXXXXXXXX\n";
    return;
}

bool is_unoccupied(char world[10][10], int x, int y)
{
    if (world[y][x] == ' ') return true;
    else return false;
}

bool is_occupied(char world[10][10], int x, int y)
{
    if (world[y][x] != ' ') return true;
    else return false;
}
