#include <iostream>
#include <vector>
#include <string>

class Node
{
    Node(char v = 0, int k = 3 int * p = NULL,)
    :key_(v), child_(new Node[k]), parent_(p)  
    {}
    char getkey() { return key_; }
    int * getchild(int i) { return &child_[i]; }
    int * getparent() { return &parent_;}
private:
    char key_;
    Node * child_;
    Node * parent_;
};

class Tree
{
private:
    Node * root_;
    int size_;
};


// std::ostream & operator<<(std::ostream & cout, const Node top)
// {
//     cout << "< Node: " << &top 
//          << "key: " << top.getkey() 
//          << ", parent: " <<  top.getparent();

    
//     return cout;
// }

std::vector<std::string> letterCombinations(std::string digits) 
{
    std::vector<std::string> output;
    
    return output;
}

int main()
{
    std::string digits = "29";
    //std::cout << letterCombinations(digits) << '\n'; 
    return 0;
}