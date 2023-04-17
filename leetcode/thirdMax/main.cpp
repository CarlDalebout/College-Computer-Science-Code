#include <iostream>
#include <vector>
#include <functional>
#include <string>

void print(std::vector<int>& nums)
{
    std::string dir = "";
    for(int i = 0; i < nums.size(); ++i)
    {
        std::cout << dir << nums[i]; dir = ", ";
    }
}

int thirdMax(std::vector<int>& nums) 
{
    std::sort(nums.begin(), nums.end());
    if(nums.size() < 3)
    {
       return nums.back();
    }
    int value = nums.back();
    int counter = 0;
    //std::cout << value << '\n';
    for(int i = nums.size()-1; i >= 0; --i)
    { 
        if(nums[i] != value)
        {
            value = nums[i];
            ++counter;
            //std::cout << value << ' ' << counter << '\n';
            if(counter == 2)
            {
                return value;
            }
        }
    }
    return nums.back();
}

int main()
{
    std::vector<int> x = {1,3,2,2};
    std::cout << thirdMax(x) << '\n';
    //print(x);
}