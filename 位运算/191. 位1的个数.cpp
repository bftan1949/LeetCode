//二进制:0b 八进制:0 十六进制:0x
class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            // 如果第i位为0,则n&(1<<i)=0,否则非0
            if (n & (1 << i)) {
                ret++;
            }
        }
        return ret;
    }
};
