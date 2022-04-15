class Solution {
   public:
    bool isPowerOfTwo(int n) {
        int count = 0;
        if (n <= 0)
            return false;
        for (int i = 0; i < 32; i++)
            count += ((n >> i) & 1);
        if (count > 1)
            return false;
        else
            return true;
    }
};
