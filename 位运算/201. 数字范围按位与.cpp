#include <iostream>
using namespace std;

/*
这道题的本质是让找left和right二进制的公共部分,比如:
left = 0101 (5)     right = 0111 (7)
5和7最长连续公共子串是 01[][],5的第三位为0,则无论与什么相与结果必定为0,
第四位5和7都为1,但二进制从1到1中间必定会经过0,因此这一位相与结果也必为0
因此最终结果就为5和7的公共部分 01[0][0]
*/

class Solution {
   public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while (left < right) {
            left = left >> 1;
            right = right >> 1;
            shift++;
        }
        return left << shift;
    }
};

int main() {
    Solution s;
    cout << s.rangeBitwiseAnd(5, 7);
    return 0;
}