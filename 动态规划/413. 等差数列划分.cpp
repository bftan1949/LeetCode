#include <iostream>
#include <vector>
using namespace std;

/**
dp[i][j]表示从第i个数到第j个数是否为等差数组,即dp[i][j] = true / false
考虑dp[i][j]和dp[i+1][j-1]的关系:
    1. 如果dp[i+1][j-1]==true
        且nums[i+1]-nums[i]==nums[j]-nums[j-1] and
            nums[i+1]-nums[i]==nums[i+2]-nums[i+1]
        则dp[i][j]=true
    2. 否则dp[i+1][j-1]=false
考虑边界:
    1. 当i==j时, dp[i][i]=false, 自己本身不是一个等差数组
    2. 当j-i=1时, dp[i][j]=false, 即如果只有两个数字时,不为等差数组
查找所有dp[i][j]=true的格子
ps: 在初始化边界条件时需要设置 dp[i][j]=true if j-i==0 or j-i==1, 但不计入统计
    因为判断dp[i][j]时需要考虑dp[i+1][j-1],比如[1,2,3],2-1=3-2,但如果dp[1][1]=false,
    同样会被认为不是等差数列
*/

class Solution {
   public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if (nums.size() == 1 || nums.size() == 2)
            return 0;
        if (nums.size() == 3) {
            if (nums[1] - nums[0] == nums[2] - nums[1])
                return 1;
            else
                return 0;
        }

        vector<vector<bool>> dp(nums.size(), vector<bool>(nums.size()));
        // 初始化边界条件
        for (int i = 0; i < nums.size(); i++) {
            dp[i][i] = true;
            dp[i][i + 1] = true;
        }

        int count = 0;
        for (int i = 2; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i + j < nums.size()) {
                    if (nums[j + 1] - nums[j] == nums[j + i] - nums[j + i - 1] &&
                        nums[j + 1] - nums[j] == nums[j + 2] - nums[j + 1] &&
                        (((i == 2) || dp[j + 1][i + j - 1]))) {
                        dp[j][i + j] = true;
                        count++;
                    } else
                        dp[j][i + j] = false;
                }
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4};
    cout << solution.numberOfArithmeticSlices(nums);
    return 0;
}