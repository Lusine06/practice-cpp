
/// odds-> ascending, even-> descending
#include <iostream>
#include <vector>
#include <functional>

template <typename Compare>
void merge(std::vector<int> &A, int p, int q, int r, Compare compare)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];

    for (int j = 0; j < n2; j++)
        R[j] = A[q + j + 1];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2)
    {
        if (compare(L[i], R[j]))
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    while (i < n1)
        A[k++] = L[i++];

    while (j < n2)
        A[k++] = R[j++];
}

template <typename Compare = std::less<int>>
void mergeSort(
    std::vector<int> &A,
    int p,
    int r,
    Compare compare = Compare{})
{
    if (p < r)
    {
        int q = p + (r - p) / 2;

        mergeSort(A, p, q, compare);
        mergeSort(A, q + 1, r, compare);

        merge(A, p, q, r, compare);
    }
}

int main()
{
    std::vector<int> A = {5, 2, 4, 8, 3, 11, 9, 1, 7};

    mergeSort(A, 0, A.size() - 1,
              [](int a, int b)
              {
                  if (a % 2 != b % 2)
                      return a % 2 != 0;

                  if (a % 2 != 0)
                      return a < b;

                  return a > b;
              });

    /// mergeSort(A, 0, A.size() - 1);

    for (int x : A)
        std::cout << x << " ";

    return 0;
}