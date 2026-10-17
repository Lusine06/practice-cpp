
#include <iostream>

long long countValidNumbers(int n)
{
    if (n == 1)
    {
        return 9;
    }

    long long same = 9;
    long long diff = 0;

    for (int i = 2; i <= n; i++)
    {
        long long new_same = diff;
        long long new_diff = same * 9 + diff * 8;

        same = new_same;
        diff = new_diff;
    }

    return diff;
}

int main()
{
    int n;
    std::cout << "Enter n: \n";
    std::cin >> n;

    std::cout << countValidNumbers(n) << std::endl;

    return 0;
}