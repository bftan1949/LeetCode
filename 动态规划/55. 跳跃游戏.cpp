#include <iostream>
#include <vector>
using namespace std;

// dp[i]表示到达第i个位置时最大还剩几步，如果dp[i]>1，则可以到达第i个位置
// 比如 [2,3,1,1,4] dp[1]=2（2到3最大还剩2步)
// dp[2]=3(如果从2出发不停留3，则到1时还剩1步，但如果从3出发，则到1时还剩3步)
// dp[i] = max{dp[i-1]-1,nums[i-1]}, 如果dp[i]>=1， 则说明可以到第i个位置
// 边界条件dp[0] = nums[0]
// 如果nums.size()==1，则return true
// 如果中间存在任何一个位置到达不了，则最后一个位置也必定无法到达，直接return false

class Solution {
   public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1)
            return true;
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int j = 1; j < nums.size(); j++) {
            dp[j] = max(dp[j - 1] - 1, nums[j - 1]);
            if (dp[j] <= 0)
                return false;
        }
        return dp[nums.size() - 1];
    }
};

int main() {
    vector<int> nums = {0, 2, 3};
    Solution s;
    cout << s.canJump(nums);
    return 0;
}