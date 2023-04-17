#ifndef SLLIST_H
#define SLLIST_H
#include <iostream>
#include "SLNode.h"

class SLList// std::forward_list
{
public:
    SLList()
    :size_(0), phead_(NULL)
    {}
    SLNode * phead() const { return phead_; } 
    int size() const { return size_; }
    void insertH(int key);
    void insertH(SLNode * node);
    void deleteH();
    void deleteT();
    
private:
    SLNode * phead_;
    int size_;
};

std::ostream & operator<<(std::ostream & cout, SLList const & list);

#endif