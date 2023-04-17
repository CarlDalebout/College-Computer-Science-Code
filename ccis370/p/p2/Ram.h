#ifndef RAM_H
#define RAM_H

#include <iostream>
#include <vector>

struct proces
{
    std::string name;
    int address;
    int size;
};

class RAM
{
public:

    RAM(int size = 0)
    :size_(size)
    {}
    ~RAM()
    {}

    void create(int size)
    {
        if(size_ != 0)
        {
            std::cout << "RAM HAS ALREADY BEEN ALLOCATED\n";
            return;
        }
        size_ = size;
        remaining_space_ = size;
    }

    void process(std::string name, int size);

    int  getindex(std::string name);

    int  loc(std::string name, int loc);

    void stop(std::string name);
    
    void dump();

    void defrag();

    std::vector<proces> process_ ;
    int size_ = 0;
    int remaining_space_ = 0;
};

#endif