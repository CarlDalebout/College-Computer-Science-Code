#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node // maybe struct
{
public:
    Node(int key = 999, Node * parent=NULL, Node * left=NULL, Node * right=NULL)
    :key_(key), parent_(parent), left_(left), right_(right)
    {}

    

// private:
    int key_;
    Node * parent_;
    Node * left_;
    Node * right_; 
};

std::ostream & operator<<(std::ostream & cout, Node & node)
{
    cout << "<Node " << &node
         << " key: " << node.key_
         << ", parent: " << node.parent_
         << ", left: " << node.left_
         << ", right: " << node.right_
         << ">\n";
    return cout;
}

#endif