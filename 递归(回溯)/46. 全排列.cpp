class Solution {
   private:
    vector<vector<int>> ans;

   public:
    vector<vector<int>> permute(vector<int>& nums) {
        perm(nums, 0);
        return ans;
    }
    // 采用回溯法 (回溯树)
    void perm(vector<int>& nums, int i) {
        int n = nums.size();
        if (i == n - 1)
            ans.push_back(nums);
        else {
            for (int j = i; j < n; j++) {
                swap(nums[i], nums[j]);
                perm(nums, i + 1);
                swap(nums[i], nums[j]);
            }
        }
    }
};
