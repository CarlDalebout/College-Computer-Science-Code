#include <iostream>
#include <stack>
#include <list>
#include "Node.h"

/*

             
                    10
        5                   8
    6       3           7
                9
*/

Node * copy_constructor(Node * q)
{
    if (q == NULL)
    {
        return NULL;
    }
    else
    {
        Node * p = new Node(q->key_);
        p->left_ = copy_constructor(q->left_);
        p->right_ = copy_constructor(q->right_);
        return p;
    }
}

void copy_constructor(Node *& p, Node * q)
{
    if (q == NULL)
    {
        p = NULL;
    }
    else
    {
        p = new Node;
        p->key_ = q->key_;
        copy_constructor(p, q);
    }
}

int max(int x, int y)
{
    return (x >= y ? x : y);
}

int hight(Node* proot)
{
    if(proot == NULL)
    {
        return -1;
    }
    else
    {
        std::cout << "height recursion ... left ...\n";
        int leftht = hight(proot->left_);
        std::cout << "hight recursion ... right .. \n";
        int rightht = hight(proot->right_);
        int ht = 1 + max(leftht, rightht);
        std::cout << "hight recursion ... return ... " << ht << '\n';
        return 1 + max(leftht, rightht);
    }
}

int size(Node* proot)
{
    if(proot == NULL)
    {
        std::cout << "size ... proot: " << proot << " ... returning 0\n";
        return 0;
    }
    else 
    {
        int leftsize = size(proot->left_);
        std::cout <<  "size ... " << proot << " ... recursion ... left ..." << leftsize << "\n";
        int rightsize = size(proot->right_);
        std::cout <<  "size ... " << proot << " ... recursion ... right ..." << rightsize << "\n";
        int size = 1+leftsize+rightsize;
        std::cout << "size ... " << proot << " ... recursion ... return ..." << size << '\n';
        return size;
    }
}

bool same(Node* p1, Node* p2)
{
    if(p1 == NULL && p2 == NULL)
    {
        return true;
    }
    else if(p1 != NULL || p2 != NULL)
    {
        return false;
    }
    else
    {
        return (p1->key_ == p2->key_) && same(p1->left_, p2->left_) && same(p1->right_, p2->right_);
    }
}

//NOT DONE
void balanceTB(Node * proot)
{
    int lefthight = hight(proot->left_);
    int righthight = hight(proot->right_);
    if(lefthight - righthight < -1 && lefthight - righthight > 1)
    {
        (lefthight > righthight) ? balance(proot->left_) : balance(proot->right_);
    }
}

//NOT DONE
void balanceBT(Node * proot)
{
    int lefthight = hight(proot->left_);
    int righthight = hight(proot->right_);
    if()

}

void bst_insert(Node*& proot, int k)
{
    if(proot == NULL)
    {
        proot = new Node(k);

        return;
    }
    else
    {
        if(proot->key_ >= k)
        {
            if(proot->left_ == NULL)
            {
                Node temp(k, proot);
                proot->left_ = temp;
            }
            else
            {
               return bst_insert(proot->left_, k);
            }
        }
        else if(proot->key_ < k)
        {
            if(proot->right_ == NULL)
            {
                Node temp(k, proot);
                proot->right_ = temp;
            }
            else
            {
               return bst_insert(proot->right_, k);
            }
        }
    }
}

void avl_insert(Node*& proot, int k)
{
    Node * newnode = bst_insert(proot, k);
    balanceBT(proot);
}

Node * bst_find(Node* proot, int k)
{
    if(proot == NULL)
    {
        return NULL;
    }
    else
    {
        if(proot->key_ > k)
        {
            return bst_find(proot->left_, k);
        }
        else if(proot->key_ < k)
        {
            return bst_find(proot->right_, k);
        }
        else 
        {
            return proot;
        }
    }
}

/*
            ap                             bp
    t1             b       ->       a              t3
                t2   t3         t1     t2
*/
//NOT DONE
void lrot(Node* proot)
{
    proot->key_ <= proot->parent_->key_ ? proot->parent_->left_ = proot->right_ : proot->parent_->right_ = proot->right_;
    proot->right_->parent_ = proot->parent_;
    proot->parent_ = proot->right_;
    proot->parent_->left_ = proot;
    proot->right_ = proot->right_->left_;
    proot->right_->parent_ = proot;

}

/*
                a                               b
        b              t3       ->      t1              a
    t1      t2                                      t2      t3
*/
//NOT DONE
void rrot(Node * proot)
{
    
}

void preorder_iteration_(Node* proot)
{
    std::stack< Node * > list;
    list.push(proot);
    while(!list.empty())
    {
        Node * p = list.top();
        list.pop();
        if(p == NULL)
        {
            std::cout << "*, ";
        }
        else
        {
            std::cout << p->key_ << " ";
            list.push(p->right_);
            list.push(p->left_);
        }
    }
}

void inorder_iteration_(Node* proot)
{
    std::stack< Node * > list;
    list.push(proot);
    while(!list.empty())
    {
        Node * p = list.top();
        list.pop();
        if(p == NULL)
        {
            std::cout << "*, ";
        }
        else
        {
            list.push(p->right_);
            std::cout << p->key_ << " ";
            list.push(p->left_);
        }
    }
}

void postorder_iteration_(Node* proot)
{
    std::stack< Node * > list;
    list.push(proot);
    while(!list.empty())
    {
        Node * p = list.top();
        list.pop();
        if(p == NULL)
        {
            std::cout << "*, ";
        }
        else
        {
            list.push(p->right_);
            list.push(p->left_);
            std::cout << p->key_ << " ";
        }
    }
}

void breath_first_iteration_(Node * proot)
{
    std::list<Node *> q;
    q.push_back(proot);
    while(!q.empty())
    {
        Node * p = q.front();
        q.pop_front();
        if(p == NULL)
        {
            std::cout << "*, ";
        }
        else
        {
            std::cout << p->key_ << ' ';
            q.push_back(p->left_);
            q.push_back(p->right_);
        }
    }
}

void preorder_print(Node* proot)
{
    if(proot == NULL)
    {
        std::cout << "*, ";
        return;
    }
    else
    {
        std::cout << proot->key_ << ", ";
        preorder_print(proot->left_);
        preorder_print(proot->right_);
    }
}

void inorder_print(Node* proot)
{
    if(proot == NULL)
    {
        std::cout << "*, ";
        return;
    }
    else
    {
        inorder_print(proot->left_);
        std::cout << proot->key_ << ", ";
        inorder_print(proot->right_);
    }
}

void postorder_print(Node* proot)
{
    if(proot == NULL)
    {
        std::cout << "*, ";
        return;
    }
    else
    {
        postorder_print(proot->left_);
        postorder_print(proot->right_);
        std::cout << proot->key_ << ", ";
    }
}

//NOT DONE
void bst_delete(Node * proot, int k)
{
    Node * node = bst_find(k);
    bst_delete(node);
}

//NOT DONE
void bst_delete(Node * node)
{
    if(node->left_ == NULL && node->right_ == NULL)
    {
        if(node->parent_->left_ == node)
        {
            node->parent_->left_ == NULL;
            delete node;
        }
        else if(node->parent_->right_ == node)
        {
            node->parent_->right_ == NULL;
            delete node;
        }
    }
}


void avl_delete(Node* node, int k)
{
    Node * node = bst_find(k);
    avl_delete(node);
}

//NOT DONE
void avl_delete(Node* node)
{


}

void delete_(Node* proot)
{
    if(proot == NULL)
    {
        return;
    }
    else
    {
        delete_(proot->left_);
        delete_(proot->right_);
        delete proot;
    }
}

/*
breath first

deepth first (Preference is usually DF (AI))
 1)preorder DF
 2)inorder DF
 3)postorder DR

 Branch and bound you go as far left until you find a value less then your range then go right

 N is hight balanced so long as the hight of the left sub tree and the hight of the right sub tree defers by at most one
*/

int main()
{
    Node * p10 = new Node(10);
    Node * p5 = new Node(5);
    Node * p6 = new Node(6);
    Node * p3 = new Node(3);
    Node * p9 = new Node(9);
    Node * p8 = new Node(8);
    Node * p7 = new Node(7);
    
    p10->left_ = p5; p10->right_ = p8;
    p5->parent_ = p10; p5->left_ = p6; p5->right_ = p3;
    p8->parent_ = p10; p8->left_ = p7;
    p6->parent_ = p5; 
    p3->parent_ = p5; p3->right_ = p9;
    p7->parent_ = p8;
    p9->parent_ = p3;

    // std::cout << (*p10) << std::endl; 
    // std::cout << (*p5) << std::endl; 
    // std::cout << (*p8) << std::endl; 
    // std::cout << (*p6) << std::endl; 
    // std::cout << (*p3) << std::endl; 
    // std::cout << (*p7) << std::endl; 
    // std::cout << (*p9) << std::endl; 

    // std::cout << hight(p10) << std::endl;
    // std::cout << size(p10) << std::endl;
    // std::cout << size(p3) << std::endl;

    preorder_iteration_(p10);
    std::cout << std::endl;
    inorder_iteration_(p10);
    std::cout << std::endl;
    postorder_iteration_(p10);
    std::cout << std::endl;
    breath_first_iteration_(p10);
    std::cout << std::endl;

    Node * q = copy_constructor(p10);
    breath_first_iteration_(q);
    std::cout << '\n' << p10 << ' ' << q << std::endl;
    delete_(p10);
    delete_(q);

    return 0;
}