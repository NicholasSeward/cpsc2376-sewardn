
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> nums;
    nums.push_back(34);
    nums.push_back(34);
    nums.push_back(45);
    nums.push_back(87);
    nums.push_back(rand());
    std::cout << nums.size() << "Hello World!\n";
}