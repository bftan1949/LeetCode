#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
dp[i][j]表示text1[1:i]和text2[1:j]的最长公共子序列
()text[i]
()text[j]
考虑dp[i][j]的递推公式:
    1. 如果text1[i]==text2[j], 则dp[i][j]==dp[i-1][j-1]+1;
    2. 如果text1[i]!=text2[j], 则存在以下两种可能情况
        1. {abce[d]e}
           {ac[e]}
           d!=e, 如果dp[i][j]==dp[i-1][j-1], 则dp[i][j]=2,
           但实际上还需要考虑{abce}和{ac[e]}的关系,因此dp[i][j]=3, 公共子序列为 {a,c,e},
        2. {ac[e]}
           {abce[d]e}
           e!=d, 考虑{ac[e]}和{abce}的关系,因此dp[i][j]=3, 公共子序列为 {a,c,e},
        因此dp[i][j] = max(dp[i-1][j],dp[i][j-1])
边界条件:
    dp[0][j] = 0
    dp[i][0] = 0
ps: dp数组从下标1开始使用
 */

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};

int main() {
    string text1 = "abc";
    string text2 = "def";
    Solution s;
    cout << s.longestCommonSubsequence(text1, text2);
    return 0;
}