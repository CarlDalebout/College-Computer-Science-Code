#include <iostream>
#include "Vec2.h"

int main()
{
    Vec2<double> vec1(3, 9);
    Vec2<double> vec2(3, 9);
    Vec2<double> vec3;
    vec3 = (vec1 * 3);

    std::cout << vec3 <<'\n'; 
    return 0;
}
