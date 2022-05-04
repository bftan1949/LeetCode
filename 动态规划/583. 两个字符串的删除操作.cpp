#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
dp[i][j]表示把word1[0:i]变成和word2[0:j]相同的最小步骤
1. dp[i][j] = dp[i-1][j-1] if word1[i]==word2[j]
    如果word1[i]==word2[j], 则这一步不需要任何操作,
    又因为word1[0:i-1]和word2[0:j-1]以及完成了匹配, 因此dp[i][j] = dp[i-1][j-1]
2. dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1 if word1[i]!=word2[j]
    如果word1[i]!=word2[j], 假如删除掉word1[i], 则剩下word1[0:i-1]与word2[0:j]配对
    同理删除word2[j], 因此dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1
边界条件
dp[0][j]=j ([s,e,a] 和 [] 配对, 则配对到哪个字符就要删掉它, 只有这样才能配对)
dp[i][0]=i ([] 和 [e,a,t] 配对, 则配对到哪个字符就要删掉它, 只有这样才能配对)
ps: dp数组从下标1开始使用
*/

class Solution {
   public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

        // 处理边界条件
        for (int i = 0; i <= word1.size(); i++)
            dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++)
            dp[0][j] = j;

        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }

        return dp[word1.size()][word2.size()];
    }
};

int main() {
    return 0;
}