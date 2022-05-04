#include <iostream>
using namespace std;

// dp[i][j]表示到达(i,j)的路径
// dp[i][j] = dp[i-1][j] + dp[i][j-1]
// dp[0][j] = 1
// dp[i][0] = 1

class Solution {
   private:
    int dp[100][100];

   public:
    int uniquePaths(int m, int n) {
        // 初始化边界条件
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
        return dp[m - 1][n - 1];
    }
};

int main() {
    return 0;
}