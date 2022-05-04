#include <iostream>
#include <vector>
using namespace std;

/*
dp[i]表示跳跃到第i个位置用的最少步,则可得到以下关系:
    dp[i+1]到dp[i+nums[i]]=min{dp[i]+1,dp[j]} (j∈[i+1,i+nums[i]])
    则dp[n-1]即为所求答案
边界条件:
    dp[0]=0
*/

class Solution {
   public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0x3f3f3f3f);
        dp[0] = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 1; j <= nums[i]; j++) {
                if (i + j < nums.size())
                    dp[i + j] = min(dp[i] + 1, dp[i + j]);
            }
        }
        return dp[nums.size() - 1];
    }
};

int main() {
    return 0;
}