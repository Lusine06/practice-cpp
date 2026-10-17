#include <vector>
using namespace std;

int minimumSwaps(vector<int> arr)
{
    int swaps = 0;
    int i = 0;

    while (i < arr.size())
    {
        if (arr[i] != i + 1)
        {
            swap(arr[i], arr[arr[i] - 1]);
            swaps++;
        }
        else
        {
            i++;
        }
    }

    return swaps;
}