#include <iostream>
#include "Tree.h"

int main() {

    Tree tree;
    // Create a new k-ary tree and insert some nodes
    KTreeNode* root = new KTreeNode(1);
    tree.insert(tree.proot_, 1, 2);
    tree.insert(tree.proot_, 1, 3);
    tree.insert(tree.proot_, 1, 4);
    tree.insert(tree.proot_, 2, 5);
    tree.insert(tree.proot_, 2, 6);
    tree.insert(tree.proot_, 4, 7);

    // Print the values of the nodes in the k-ary tree
    tree.print(tree.proot_);

    return 0;
}