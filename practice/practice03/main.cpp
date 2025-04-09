
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <unordered_map>


template<typename T>
T addNums(T x, T y)
{
    return x + y;
}

template<typename T>
T getInput(std::string prompt)
{
    while (true)
    {
        std::cout << prompt;
        T output;
        std::cin >> output;
        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "invalid input\n";
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return output;
    }
}


template<>
std::string getInput<std::string>(std::string prompt)
{
    std::cout << prompt;
    std::string output;
    std::getline(std::cin, output);

    return output;
}


int main()
{
    std::deque<int> nums;
    nums.push_back(99);
    nums.push_front(88);
    nums.push_front(1);
    for (int num : nums)
    {
        std::cout << num << ", ";
    }
    std::cout << "\n";

    




}
