#include <vector>
using namespace std;
// 2D array (6x6) ... missing part


int hourglassSum(vector<vector<int>> arr){
    int maxSum = -63;

    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
            int currentSum = arr[i][j]     + arr[i][j+1]   + arr[i][j+2]
                                         + arr[i+1][j+1]
                           + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];

            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }

    return maxSum;
}