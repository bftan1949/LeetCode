#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
设dp[i]表示到第i位时能解码的方法数
首先发现如果s[0]=='0',则没有合理组合,return 0
观察dp[i]和dp[i-1]
1. 假设第i个数不和第i-1个数组合,则dp[i]+=dp[i-1]
    比如: "216", 6不和1组合,则可为[2,1,6],[21,6]
2. 假设第i个数和第i-1个数组合,如果不违法,则dp[i]+=dp[i-2]
    比如: "216", 6和1组合,则可为[2,16]
dp[i]+=dp[i-1] if s[i] != '0' (因为'0'无法单独表示)
dp[i]+=dp[i-2] if s[i-1 to i]合法
边界条件:
    1. 如果只有1个数,且不为'0',则dp[1]=1,否则为dp[1]=0
    2. dp[0]=1,以方便两个数时进行计算,dp从下标1开始
*/

class Solution {
   public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;

        vector<int> dp(s.size() + 1);
        // 处理边界条件
        dp[0] = 1;
        if (s[0] == '0')
            dp[1] = 0;
        else
            dp[1] = 1;
        for (int j = 2; j <= s.size(); j++) {
            if (s[j - 1] != '0')
                dp[j] += dp[j - 1];
            if (s.substr(j - 2, 2) >= "10" && s.substr(j - 2, 2) <= "26")
                dp[j] += dp[j - 2];
        }
        return dp[s.size()];
    }
};

int main() {
    string s = "10011";
    Solution solution;
    cout << solution.numDecodings(s);
    return 0;
}