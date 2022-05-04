#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
设dp[i][j]表示将word1[0:j]变成word2[0:i]需要几步
考虑dp[i][j]和周边元素的关系
    1. 如果word1[j]==word2[i],则在这一步无需任何操作,因此dp[i][j]=dp[i-1][j-1]
    2. 如果word1[j]!=word2[i]:
        1. 替换操作, 则替换完成后word1[j]=word2[i], dp[i][j]=dp[i-1][j-1]+1 (+1是替换的步骤)
        2. 删除word1[j], 则剩下word1[0:j-1]和word2[0:i], dp[i][j]=dp[i][j-1]+1
        3. 插入操作, 插入操作其实等效于删除word2[i], 比如:
            word1: {...,[c]} ...代表已经处理好的字符串, word1和word2的...一定是相等的
            word2: {...,[e]}
            在word1的[c]前面插入e,则变成{...,e,[c]},word2为{...,[e]},
            相当于word2本来为{...,e,[.]},删除掉[.]
            因此dp[i][j] = dp[i-1][j]+1
边界条件:
    dp[0][j] = j
    dp[i][0] = i
ps: dp从下标1开始
*/

class Solution {
   public:
    int min(int x, int y, int z) {
        if (x < y && x < z)
            return x;
        else if (y < z)
            return y;
        else
            return z;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word2.size() + 1, vector<int>(word1.size() + 1, 0));
        for (int j = 0; j <= word1.size(); j++)
            dp[0][j] = j;
        for (int i = 0; i <= word2.size(); i++)
            dp[i][0] = i;

        for (int i = 1; i <= word2.size(); i++) {
            for (int j = 1; j <= word1.size(); j++) {
                if (word1[j - 1] != word2[i - 1])
                    dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]) + 1;
                else
                    dp[i][j] = dp[i - 1][j - 1];
            }
        }

        return dp[word2.size()][word1.size()];
    }
};

int main() {
    string word1 = "horse";
    string word2 = "ros";
    Solution s;
    cout << s.minDistance(word1, word2);
    return 0;
}