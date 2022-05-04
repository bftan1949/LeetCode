#include <iostream>
#include <string>
using namespace std;

/**
dp[i][j]表示字符串(s[i],...,s[j])是否能构成回文串, 即dp[i][j] = true / false
考虑dp[i][j]和dp[i+1][j-1]的关系:
    1. 如果s[i]==s[j]且dp[i+1][j-1]==true,则dp[i][j]=true
    2. 否则dp[i+1][j-1]=false
这里法否则存在以下几种情况:
    1. s[i]!=s[j]
    2. s[i]==s[j] but dp[i+1][j-1]==false
    3. i>j
考虑边界:
    1. 当i==j时, dp[i][i]=true, 即自己本身就是一个回文串
    2. 当j-i=1时, dp[i][j]=true if s[i]==s[j] else dp[i][j]=false,
        即如果只有两个字符时,如果两个字符相等即为回文串,否则不为回文串
查找所有dp[i][j]=true的格子, 找出j-i最大的回文串
ps: 要注意遍历的顺序
    [[dp[0,0],dp[0,1],dp[0,2]],
     [dp[1,0],dp[1,1],dp[1,2]],
     [dp[2,0],dp[2,1],dp[2,2]]]
    dp[0,0] -> dp[1,1] -> dp[2,2]
    dp[0,1] -> dp[1,2]
    dp[0,2]
    因为要知道dp[i,j], 需要先知道dp[i+1,j-1]
 */

class Solution {
   private:
    bool dp[1000][1000] = {false};

   public:
    string longestPalindrome(string s) {
        if (s.size() == 1)
            return s.substr(0, s.size());
        if (s.size() == 2) {
            if (s[0] == s[1])
                return s.substr(0, s.size());
            else
                return s.substr(0, 1);
        }

        // 初始化边界条件
        for (int i = 0; i < s.size(); i++)
            dp[i][i] = true;

        int maxLen = 0;
        int index = 0;
        for (int i = 1; i < s.size(); i++) {
            for (int j = 0; j < s.size(); j++) {
                if (i + j < s.size()) {
                    if (s[j] == s[i + j] && (((i == 1) || dp[j + 1][i + j - 1]))) {
                        dp[j][i + j] = true;
                        if (i > maxLen) {
                            maxLen = i;
                            index = j;
                        }
                    } else
                        dp[j][i + j] = false;
                }
            }
        }
        // substr的第二个参数是要截取的字符串长度
        return s.substr(index, maxLen + 1);
    }
};

int main() {
    Solution solution;
    string s = "aaaa";
    cout << solution.longestPalindrome(s);
    return 0;
}