#include "SLList.h"
#include <string>

void SLList::insertH(int key)
{
    phead_ = new SLNode(key, phead_);
    size_++;
}
void SLList::insertH(SLNode * node)
{
    phead_ = new SLNode(node->key(), phead_);
    size_++;
}
void SLList::deleteH()
{
    if(phead_ != NULL)
    {
        SLNode * temp = phead_;
        phead_ = phead_->next_;
        delete temp;
        size_--;
    }
}
// void SLList::insertT(int key, SLNode * next);
// void SLList::deleteT(int key, SLNode * next);

std::ostream & operator<<(std::ostream & cout, SLList const & list)
{
    SLNode * p = list.phead();   
    cout << "SLList: " << &list << "\t Size: " << list.size() << "\n<";
    while(p != NULL)
    {   
        std::cout << "\n " << (*p);
        p = p->next_;
    }
    cout << "\n>";

    
        // SLNode * p = list.phead();
        // cout << '[';
        // std::string delim = "";
        // while(p != NULL)
        // {
        //     std::cout << delim << (*p); delim = ", ";
        //     p = p->next_;
        // }
        // std::cout << ']';
    
    return cout;
}