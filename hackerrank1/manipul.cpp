///variant 1
///time complexity  O(m+n)

#include <iostream>
#include <vector>
using namespace std;
long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> arr(n + 2, 0);

    for (size_t i = 0; i < queries.size(); i++) {
        int a = queries[i][0];
        int b = queries[i][1];
        int k = queries[i][2];

        arr[a] += k;        
        arr[b + 1] -= k;  
    }

    long max_val = 0; 
    long current_sum = 0;

    for (int i = 1; i <= n; i++) {
        current_sum += arr[i];
        if (current_sum > max_val) {
            max_val = current_sum;
        }
    }

    return max_val;
}


/// variant 2
///time complexity  O(m*n)


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long arrayManipulationNaive(int n, vector<vector<int>> queries) {
    vector<long> arr(n + 1, 0);

    for (size_t i = 0; i < queries.size(); i++) {
        int a = queries[i][0];
        int b = queries[i][1];
        int k = queries[i][2];

        for (int j = a; j <= b; j++) {
            arr[j] += k;
        }
    }

    long max_val = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    return max_val;
}