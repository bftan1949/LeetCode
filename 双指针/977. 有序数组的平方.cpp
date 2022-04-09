class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res;
        int idx = -1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] * nums[i] <= 0)
                idx = i;
        }
        if (idx == -1) {
            if (nums[0] < 0) {
                for (int k = nums.size() - 1; k >= 0; k--)
                    res.push_back(nums[k] * nums[k]);
            } else {
                for (int k = 0; k < nums.size(); k++)
                    res.push_back(nums[k] * nums[k]);
            }
            return res;
        } else {
            int right = idx;
            int left = idx - 1;
            while (!(left < 0 || right > nums.size() - 1)) {
                if (nums[left] * nums[left] < nums[right] * nums[right]) {
                    res.push_back(nums[left] * nums[left]);
                    left--;
                } else {
                    res.push_back(nums[right] * nums[right]);
                    right++;
                }
            }
            for (int j = left; j >= 0; j--) {
                res.push_back(nums[j] * nums[j]);
            }
            for (int j = right; j < nums.size(); j++) {
                res.push_back(nums[j] * nums[j]);
            }
            return res;
        }
    }
};
