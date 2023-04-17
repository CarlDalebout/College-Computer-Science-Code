#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <string>
#include "Node.h"

// Definition for a k-ary tree node.
struct KTreeNode {
    int val;
    std::vector<KTreeNode*> children;
    KTreeNode(int x) : val(x) {}
};

class Tree
{
public:
    Tree()
    :proot_(NULL)
    {}
    ~Tree()
    {}

    void insert(KTreeNode*, int parentVal, int val);

    void print(KTreeNode* proot);

// private:
    KTreeNode * proot_;
    int k_;
};

// // HL   HR
// // HLL  HLR  HRL  LRR  H(SL)(SR)
// // HLLL HLLR HLRL HLRR HRLL HRLR HRRL HRRR H(SLL)(SR) H(SLR)(SR) H(SL)(SRL) H(SL)(SRR) 
// // std::ostream & operator<<(std::ostream & cout, const Node top)
// // {
// //     cout << "< Node: " << &top 
// //          << "key: " << top.getkey() 
// //          << ", parent: " <<  top.getparent();

    
// //     return cout;
// // }

#endif