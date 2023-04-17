#include "DLNode.h"
#include <iomanip>

std::ostream & operator<<(std::ostream & cout, DLNode const& node)
{
    cout << "<DLNode " << &node
         << ", key: " << std::setw(3) << std::setfill(' ') << node.key()
         << ", prev: " << node.prev()
         << ", next: " << node.next()
         << ">";
    return cout;
}