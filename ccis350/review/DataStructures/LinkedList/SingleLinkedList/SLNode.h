#ifndef SLNODE_H
#define SLNODE_H
#include <iostream>

class SLNode
{
public:
    SLNode(int key, SLNode * next = NULL)
    :key_(key), next_(next)
    {}
    ~SLNode()
    {}
    int key() const { return key_; }
    SLNode * next() const { return next_; }
    void next(SLNode * next) {next_ = next;}

    void pushf(int, SLNode*);
    void pushb(int, SLNode*);

//private:
    int key_;
    SLNode * next_;
};

std::ostream & operator<<(std::ostream & cout, SLNode  const& node);
#endif