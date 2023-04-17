#include <iostream>
#include <cmath>
#include <string>

int hash(std::string name)
{
    int hash = 0;
    for(int i = 0; i < name.size(); ++i)
    {   
        std::cout << "Adding " << int(name[i]) * pow(10, i) << '\n';
        hash += int(name[i]) * pow(10, i);
    }
    return hash;
}

int main()
{
    int hashtable [10][2];
    int address = int('a') * 1 + int('b')*10 + int('e')* 100;
    hashtable[0][0] = address;
    hashtable[0][1] = 5.5;
    std::cout << hash("abe") << '\n';
}