#include <iostream>
#include <vector>
#include "Tree.h"

// Function to insert a new node into the k-ary tree
void Tree::insert(KTreeNode* root, int parentVal, int val) {
    if (root == NULL) {
        return;
    }
    if (root->val == parentVal) {
        root->children.push_back(new KTreeNode(val));
        return;
    }
    for (KTreeNode* child : root->children) {
        insert(child, parentVal, val);
    }
}

// Function to print the values of the nodes in the k-ary tree
void Tree::print(KTreeNode* root) {
    if (root == NULL) {
        return;
    }
    std::cout << root->val << " ";
    for (KTreeNode* child : root->children) {
        print(child);
    }
}
