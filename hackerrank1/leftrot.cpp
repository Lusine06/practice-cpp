#include <vector>
using namespace std;

// Left Rotation

// 1st variant
vector<int> rotLeft(vector<int> a, int d)
{
    int n = a.size();
    vector<int> result(n);

    for (size_t i = 0; i < n; i++)
    {
        result[i] = a[(i + d) % n];
    }

    return result;
}

// 2nd variant
vector<int> rotLeft(vector<int> a, int d)
{
    int n = a.size();
    vector<int> result(n);

    d = d % n; // for the cases when d >n;

    size_t k = 0;
    for (size_t i = d; i < n; i++)
        result[k++] = a[i];
    for (size_t i = 0; i < d; i++)
        result[k++] = a[i];
    return result;
}
