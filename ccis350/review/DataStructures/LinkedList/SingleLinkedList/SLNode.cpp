#include "SLNode.h"

std::ostream & operator<<(std::ostream & cout, SLNode const& node)
{
    cout << "<SLNode " << &node
         << " key: " << node.key()
         << ", next: " << node.next()
         << ">";

    // cout << node.key();
    return cout;
}