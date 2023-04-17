#ifndef DLNODE_H
#define DLNODE_H
#include <iostream>

class DLNode
{
public:
    DLNode(int key, DLNode * prev = NULL, DLNode * next = NULL)
    :key_(key), prev_(prev), next_(next) 
    {}
    ~DLNode()
    {}
    int key() const { return key_; }
    DLNode * next() const { return next_; }
    DLNode * prev() const { return prev_;}
    DLNode * next(DLNode * next) {next_ = next; return next_;}
    DLNode * prev(DLNode * prev) {prev_ = prev; return prev_;}

//private:
    int key_;
    DLNode * next_;
    DLNode * prev_;
};

std::ostream & operator<<(std::ostream & cout, DLNode  const& node);
#endif