#ifndef DLLIST_H
#define DLLIST_H
#include <iostream>
#include "DLNode.h"

class DLList// std::forward_list
{
public:
    DLList()
    :shead_(new DLNode(-9999)), 
     stail_(new DLNode(-9999, shead_, NULL)),
     size_(0)
    {
        shead_->next(stail_);
    }
    ~DLList()
    {
        
    }

    DLNode * shead() const { return shead_; } 
    DLNode * stail() const { return stail_; }
    int size() const { return size_; }
    void insertH(int key);
    void insertH(DLNode * node);
    
    void insertT(int key);
    void insertT(DLNode * node);
    
    void deleteH();
    void deleteT();
    void deleteA(DLNode *);
    // void insertT(int key, DLNode * next);
    // void deleteT(int key, DLNode * next);
    
private:
    DLNode * shead_;
    DLNode * stail_;
    int size_;
};

std::ostream & operator<<(std::ostream & cout, DLList const & list);

#endif