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
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxLen = 0, ans = 0;
        vector<int> dp(n), cnt(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = 1;
            cnt[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];  // 重置计数
                    } else if (dp[j] + 1 == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                ans = cnt[i];  // 重置计数
            } else if (dp[i] == maxLen) {
                ans += cnt[i];
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 5, 4, 7};
    cout << solution.findNumberOfLIS(nums);
    return 0;
}