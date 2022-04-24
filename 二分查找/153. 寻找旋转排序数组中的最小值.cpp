#include <iostream>
#include <vector>
using namespace std;

// 思路、推理过程和第33题一样
class Solution {
   public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else if (nums[mid] <= nums[right])
                right = mid;
        }
        return nums[left];
    }
};

int main() {
    vector<int> a = {3, 1, 2};
    Solution solution;
    cout << solution.findMin(a);
    return 0;
}