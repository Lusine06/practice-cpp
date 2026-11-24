#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>

int main()
{
    std::map<std::string, int> people = {{"Lusine", 20}, {"Ani", 21}, {"Anet", 22}};
    for (auto it = people.begin(); it != people.end(); ++it)
    {
        if (it->first == "Lusine")
            it->second += 3;
    }
    for (auto it = people.begin(); it != people.end(); ++it)
    {
        std::cout << it->first << " " << it->second << "\n";
    }
    for (const auto &name : people)
    {
        std::cout << name.first << " " << name.second << "\n";
    }
    std::vector<int> numbers = {3, 100, -8, 34, 56, 0};
    std::sort(numbers.begin(), numbers.end());
    for (auto iter = numbers.begin(); iter != numbers.end(); ++iter)
        std::cout << *iter << " ";

    std::set<std::string> cars = {"Volvo", "Toyota", "BMW", "Mersedes"};
    std::cout << "Checking if the vector is empty: ";
    std::cout << cars.empty() << "\n";
    for (auto it = cars.rbegin(); it != cars.rend(); ++it)
        std::cout << *it << " ";

    people.clear();
    numbers.clear();
    cars.clear();
    return 0;
}