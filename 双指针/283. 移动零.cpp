class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        // 把非0数按顺序全部移动到左边, 则0自然就全部被移动到右边了
        int pointer = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[pointer], nums[i]);
                pointer++;
            }
        }
    }
};