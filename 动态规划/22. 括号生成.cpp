#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// 高级版，动态规划
// dp[i]表示加上第i组括号时一共有多少种放法
// dp[i] = (dp[p]) * dp[q]  (p+q = i-1)
/**
 * 比如dp[3]则可分解为以下几种情况
 * 1. (dp[0]) dp[2] 在第三组括号里面有0组括号，在第三组括号外边有2组括号
 * 2. (dp[1]) dp[1] 在第三组括号里面有1组括号，在第三组括号外边有1组括号
 * 3. (dp[2]) dp[0] 在第三组括号里面有2组括号，在第三组括号外边有0组括号
 * 则dp[i]一共有dp[p]*dp[q]种摆放方法
 */

class Solution {
   private:
    vector<string> dp[9];
    vector<string> ans;
    string s;

   public:
    vector<string> generateParenthesis(int n) {
        // 初始化 dp[0]
        dp[0] = {""};
        // 初始化 dp[1]
        dp[1] = {"()"};
        // 从dp[2]开始计算
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                // (dp[p])的摆放方法
                for (auto p : dp[j]) {
                    // 括号外 dp[q] 的摆放方法
                    for (auto q : dp[i - 1 - j]) {
                        dp[i].push_back("(" + p + ")" + q);
                    }
                }
            }
        }
        return dp[n];
    }
};

int main() {
    Solution solution;
    solution.generateParenthesis(3);
    return 0;
}