#include <iostream>
#include <vector>
using namespace std;

/*
dp[i]表示如果以nums[i]作为子串的最后一个数字,则子串最长为多长
1. 如果nums[i]<=nums[j],则说明数字i无法加到以nums[j]为结尾的子串后面
2. 如果nums[i]>nums[j],则说明数字i可以加到以nums[j]为结尾的子串后面
    则dp[i]的一种情况可以为dp[i]=dp[j]+1
3. 遍历所有的j,找到使dp[i]最大的情况 j∈[0,i-1]
边界条件:  dp[0]=1
*/

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int best = 0;

        // 边界条件
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i])
                        dp[i] = dp[j] + 1;
                }
            }
        }

        // 查找所有dp中最大的那个
        for (int i = 0; i < nums.size(); i++) {
            if (dp[i] > best)
                best = dp[i];
        }
        return best;
    }
};

int main() {
    return 0;
}