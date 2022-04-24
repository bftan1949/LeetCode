#include <iostream>
#include <vector>
using namespace std;
/**
 * 不同于一般的二分查找，这道题需要把所有元素都找出来，因此当nums[mid]=target时
 * 还需要继续查找。
 * fir：向mid左边查找，找到第一次出现target的下标
 * sec：向mid右边查找，找到最后一次出现target的下标
 */
class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return {-1, -1};
        int first = firstBinarySearch(nums, target);
        int last = lastBinarySearch(nums, target);
        return {first, last};
    }
    // 查询第一次出现target的下标
    int firstBinarySearch(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                // 因为是要查询第一次出现,
                // 所以要接着查询[0,mid]区间里面除了mid还有没有
                right = mid;
        }
        if (left < nums.size() && nums[left] == target)
            return left;
        else
            return -1;
    }
    // 查询最后一次出现target的下标
    int lastBinarySearch(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            // 因为left=mid, 所以 (left+right)/2=left=mid, 会进入死循环,所以加1
            int mid = (left + right + 1) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else
                // 因为是要查询最后一次出现,
                // 所以要接着查询[mid,len-1]区间里面除了mid还有没有
                left = mid;
        }
        if (left < nums.size() && nums[left] == target)
            return left;
        else
            return -1;
    }
};
int main() {
    vector<int> a = {};
    Solution solution;
    a = solution.searchRange(a, 6);
    for (int i = 0; i < 2; i++)
        cout << a[i] << " ";
    return 0;
}