#include "DLList.h"

void DLList::insertH(int key)
{
    DLNode * temp = new DLNode(key, shead_, shead_->next_);
    shead_->next(temp);
    temp->next()->prev(temp);

    /*

    */
    size_++;
}
void DLList::insertH(DLNode * node)
{
    insertH(node->key());
}

void DLList::insertT(int key)
{
    DLNode * temp = new DLNode(key, stail_->prev_, stail_);
    stail_->prev(temp);
    temp->prev()->next(temp);
    size_++;
}
void DLList::insertT(DLNode * node)
{
    insertT(node->key());
}

void DLList::deleteH()
{
    if(size() > 0)
    {
        DLNode * temp = shead_->next_;
        temp->prev()->next(temp->next());
        temp->next()->prev(temp->prev());
        delete temp;
        size_--;

        /*
            DLNode * p = shead_;
            p->prev()->next(p->next());
            p->next()->prev(p->prev());
            delete p;
        */
    }
}
void DLList::deleteT()
{
    DLNode * temp = stail_->prev_;
    stail_->prev(temp->prev_);
    temp->prev(temp->next(stail_));
    delete temp;
    size_--;

    /*
        DLNode * p = stail_;
        p->
    */
}
void DLList::deleteA(DLNode * temp)
{
    temp->prev()->next(temp->next());
    temp->next()->prev(temp->prev());
    delete temp;
    size_--;
}

std::ostream & operator<<(std::ostream & cout, DLList const & list)
{
    DLNode * p = list.shead()->next();   
    std::cout << "shead " << list.shead() << " ptail " << list.stail() << '\n';
    cout << "DLList: " << &list << "\t Size: " << list.size() << "\n<\n";
    while(p->next() != NULL)
    {   
        std::cout << " " << (*p) << '\n';
        p = p->next_;
    }
    cout << ">";
    return cout;
}