#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
dp[i]表示amount=i时的最少硬币个数
考虑dp[i]和dp[i-1]的关系,如果知道了dp[i-1],则只需要再加1枚1元的就是dp[i]
同理,如果知道了dp[i-n],则只需要再加1枚n元的就是dp[i]
因此dp[i]=min(dp[i-n])+1 (+1是加一枚n元硬币, n∈coins)
1. dp[0] = 0                (amount=0,则无需硬币)
2. dp[i] = -1               (i<0)
3. dp[i] = min(dp[i-n])+1   (n∈coins)
*/

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < (int)coins.size(); ++j) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main() {
    return 0;
}