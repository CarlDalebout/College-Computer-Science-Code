#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include "Node.h"


class BinTree
{
public:
    BinTree()
    :proot(NULL)
    {}
    BinTree(Node * proot)
    {}
    ~BinTree()
    {
        
    }

    int hight() const;
    int size() const;

// private:
    Node * proot;
};

#endif