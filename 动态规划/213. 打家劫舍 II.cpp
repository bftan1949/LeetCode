#include <iostream>
#include <vector>
using namespace std;

// dp[i][j]表示从第i户开始偷，偷到第j户最多能偷多少
// dp[i][j] = max{dp[i][j-2] + nums[j], dp[i][j-1]}
// dp[i][i] = nums[i]
// dp[i][i+1] = max{nums[i],nums[i+1]}

class Solution {
   public:
    int robRange(vector<int>& nums, int start, int end) {
        int first = nums[start], second = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }

    int rob(vector<int>& nums) {
        int length = nums.size();
        if (length == 1) {
            return nums[0];
        } else if (length == 2) {
            return max(nums[0], nums[1]);
        }
        return max(robRange(nums, 0, length - 2), robRange(nums, 1, length - 1));
    }
};

int main() {
    vector<int> nums = {2, 3, 2};
    Solution s;
    s.rob(nums);
    return 0;
}