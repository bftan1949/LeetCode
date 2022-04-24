#include <iostream>
#include <vector>
using namespace std;

// 那边比nums[mid]大，就向哪边搜索（贪心）
class Solution {
   public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right + 1) / 2;
            // 如果nums[mid]>nums[mid-1],则向[mid,len-1]搜索
            if ((mid - 1) >= 0 && nums[mid] > nums[mid - 1])
                left = mid;
            // 如果nums[mid]<=nums[mid-1],则向[0,mid-1]搜索
            else if ((mid - 1) >= 0 && nums[mid] <= nums[mid - 1])
                right = mid - 1;
        }
        return left;
    }
};

int main() {
    vector<int> a = {1, 2, 1, 3, 5, 6, 4};
    Solution solution;
    cout << solution.findPeakElement(a);
    return 0;
}