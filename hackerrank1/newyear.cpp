#include <iostream>
#include <vector>
using namespace std;

void minimumBribes(vector<int> q)
{
    int total_bribes = 0;
    int n = q.size();

    for (int i = 0; i < n; i++)
    {
        if (q[i] - (i + 1) > 2)
        {
            cout << "Too chaotic \n";
            return;
        }

        int start = max(0, q[i] - 2);
        for (int j = start; j < i; j++)
        {
            if (q[j] > q[i])
            {
                total_bribes++;
            }
        }
    }

    cout << total_bribes << endl;
}