class Solution {
   public:
    int firstBadVersion(int n) {
        long long left = 1;
        long long right = n;
        while (left <= right) {
            long long middle = (left + right) / 2;
            if (isBadVersion(middle)) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return left;
    }
};
