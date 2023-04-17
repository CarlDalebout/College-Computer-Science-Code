#include <iostream>
#include "LongInt.h"

void test_Equal_Equal()
{
    LongInt I,J;
    std::cout << "Insert I\n";
    std::cin >> I;
    std::cout << "Insert J\n";
    std::cin >> J;

    if(I == J)
        std::cout << I << " is equal to " << J << '\n'; 
    else
        std::cout << I << " is not equal to " << J << '\n'; 
}

void test_Not_Equal()
{
    LongInt I,J;
    std::cin >> I >> J;

    if(I != J)
        std::cout << I << " is not equal to " << J << '\n'; 
    else
        std::cout << I << " is equal to " << J << '\n'; 

}

void test_Greater_then()
{
    LongInt I,J;
    std::cin >> I >> J;

    if(I > J)
        std::cout << I << " is greater then " << J << '\n'; 
    else
        std::cout << I << " is not greater then " << J << '\n'; 

}

void test_Greater_then_Equal()
{
    LongInt I,J;
    std::cin >> I >> J;

    if(I >= J)
        std::cout << I << " is greater then or equal " << J << '\n'; 
    else
        std::cout << I << " is not greater then  or equal" << J << '\n'; 

}

void test_Less_then()
{
    LongInt I,J;
    std::cin >> I >> J;

    if(I < J)
        std::cout << I << " is less then " << J << '\n'; 
    else
        std::cout << I << " is not less then " << J << '\n'; 

}

void test_Less_then_Equal()
{
    LongInt I,J;
    std::cin >> I >> J;

    if(I <= J)
        std::cout << I << " is less then or equal" << J << '\n'; 
    else
        std::cout << I << " is not less then or equal " << J << '\n'; 

}

void test_add_LL()
{
    LongInt I,J;
    std::cin >> I >> J;

    std::cout << I << '+' << J << '=' << (I + J) << '\n';

}

void test_sub_LL()
{
    LongInt I,J;
    std::cin >> I >> J;

    std::cout << I << '-' << J << '=' << (I - J) << '\n';

}

void test_add_LI()
{
    LongInt I;
    int J;
    std::cin >> I >> J;

    std::cout << I << '+' << J << '=' << (I + J) << '\n';

}

void test_sub_LI()
{
    LongInt I;
    int J;
    std::cin >> I >> J;

    std::cout << I << '-' << J << '=' << (I - J) << '\n';

}

void test_add_IL()
{
    LongInt J;
    int I;
    std::cin >> I >> J;

    std::cout << I << '+' << J << '=' << (I + J) << '\n';

}

void test_sub_IL()
{
    LongInt J;
    int I;
    std::cin >> I >> J;

    std::cout << I << '-' << J << '=' << (I - J) << '\n';

}

int main ()
{
    int option;
        std::cin >> option;
    switch(option)
    {
        case 0:
            test_Equal_Equal();
            break;
        case 1:
            test_Not_Equal();
            break;
        case 2:
            test_Greater_then();
            break;
        case 3:
            test_Greater_then_Equal();
            break;
        case 4:
            test_Less_then();
            break;
        case 5:
            test_Less_then_Equal();
            break;
        case 6:
            test_add_LL();
            break;
        case 7:
            test_sub_LL();
            break;
        case 8:
            test_add_LI();
            break;
        case 9:
            test_sub_LI();
            break;
        case 10:
            test_add_IL();
            break;
        case 11:
            test_sub_IL();
            break;
    };
    return 0;
}
