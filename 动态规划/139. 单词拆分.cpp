#include <iostream>
#include <string>
#include <unordered_set >
#include <vector>
using namespace std;

/*
dp[i] 表示前i位是否可以被表示
分解s[0:i]: s[0:j]+s[j+1:i], 如果s[0:j]可以被表示,且s[j+1:i]也可以被表示,
    则s[0:i]可以被表示
即 dp[i]=dp[j]&&check(s[j+1:i]) (j∈[0,i-1])
边界条件: dp[0]=true
*/

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet;
        for (auto word : wordDict) {
            wordDictSet.insert(word);
        }

        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
int main() {}