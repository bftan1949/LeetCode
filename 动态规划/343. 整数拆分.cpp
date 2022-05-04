#include <iostream>
#include <vector>
using namespace std;

/**
dp[i]表示正整数i拆分的整数中乘积的最大值
考虑dp[i]和dp[i-1]的关系,整数i可以由i-1再加一个1获得,且此时dp[i]=dp[i-1]*1,
同理考虑dp[i]和dp[i-n]的关系,整数i可以由i-n再加一个n获得,
    1. 此时若i-n继续拆分的话: dp[i]=dp[i-n]*n
    2. 若i-n不拆分的话: dp[i]=(i-n)*n
因此dp[i]=max{max{(i-n)*n,dp[i-n]*n}} n∈[1,i-1]
1. dp[1] = 1
2. dp[i]=max{dp[i-n]*n} n∈[1,i-1]
*/

class Solution {
   public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        for (int i = 2; i <= n; i++) {
            int curMax = 0;
            for (int j = 1; j < i; j++) {
                curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
            }
            dp[i] = curMax;
        }
        return dp[n];
    }
};

int main() {
    return 0;
}