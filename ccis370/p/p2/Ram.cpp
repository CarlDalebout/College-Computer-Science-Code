#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "Ram.h"

/* NEEDS TO GET DONE*/
void RAM::process(std::string name, int size)
{   
    proces temp {name, 0, size};
    

    if(size_ == 0)
    {
        std::cout << "RAM HAS NOT BEEN CREATED\n";
        return;
    }
    else if(size > remaining_space_)
    {
        std::cout << "Size of the process is to large\n";
        return;
    }
    else if(getindex(name) != -1)
    {
        std::cout << "process already exists\n";
        return;
    }
    
    if(process_.size() == 0)
    {

        process_.push_back(temp);
        remaining_space_ -= size;
        return;
    }
    else
    {
        int fragmented_size = 0;
        for(int i = 0; i < process_.size(); ++i)
        {
            fragmented_size = process_[i].address - temp.address;
            if(fragmented_size >= size)
            {
                process_.insert(process_.begin()+i, temp);
                remaining_space_ -= size;
                return;
            }
            else
            {
                temp.address = process_[i].address + process_[i].size;
            }
        }
        std::cout << temp.address << '\n'; 
        if(size_ - temp.address >= size)
        {
            process_.push_back(temp);
                remaining_space_ -= size;
                return;
        }
        else
        {
            RAM::defrag();
            temp.address = process_.back().address + process_.back().size;
            remaining_space_ -= size;
            process_.push_back(temp);
        }
    }
}

int RAM::getindex(std::string name)
{   
    for(int i = 0; i < process_.size(); ++i)
    {
        if(process_[i].name == name)
            return i;
    }
    //std::cout << "SEGMENTATION FAULT\n";
    return -1;
}

int RAM::loc(std::string name, int loc)
{
    int index = getindex(name);
    if(loc > process_[index].size)
    {
        std::cout << "OVERFLOW ERROR\n";
        return -1;
    }
    else
    {
        int address = process_[index].address + loc;
        return address;
    }     
}

void RAM::stop(std::string name)
{
    if(getindex(name) == -1)
    {
        std::cout << "process does not exist\n";
        return;
    }
    remaining_space_ += process_[getindex(name)].size;
    process_.erase(process_.begin() + getindex(name));    
}

void RAM::dump()
{
    if(process_.size() == 0)
    {
        std::cout << "No running programs\n";
    }
    else
    {
        std::cout << "Current running programs:\n";
        for(int i = 0; i < process_.size(); ++i)
        {
            std::cout << "\tName: " << process_[i].name << std::setw(10) << std::setfill(' ') 
                << "\tBase: " << std::setw(4) << std::setfill('0') << process_[i].address 
                << "\tBound: " << process_[i].address + process_[i].size - 1 
                << "\tSize: " << process_[i].size << '\n';
        }
        std::cout << "Remaining size: " << remaining_space_ << '\n';
    }
}

void RAM::defrag()
{
    process_[0].address = 0;
    for(int i = 1; i < process_.size(); ++i)
    {
        process_[i].address = process_[i-1].address + process_[i-1].size;
    }
}