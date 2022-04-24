#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> searchMatrix(vector<vector<int>>& matrix, int target) {
        int upperi = 0, leftj = 0;
        int bottomi = matrix.size() - 1;
        int rightj = matrix[0].size() - 1;

        // 先二分查找确定在哪一行
        while (upperi < bottomi) {
            int midi = (upperi + bottomi) / 2;
            if (matrix[midi][leftj] > target)
                bottomi = midi - 1;
            else if (matrix[midi][rightj] < target)
                upperi = midi + 1;
            else {
                upperi = midi;
                break;
            }
        }

        // 再二分查找确定在哪一列
        while (leftj < rightj) {
            int midj = (leftj + rightj) / 2;
            if (matrix[upperi][midj] > target)
                rightj = midj - 1;
            else if (matrix[upperi][midj] < target)
                leftj = midj + 1;
            else
                return {upperi, midj};
        }

        if (matrix[upperi][leftj] == target)
            return {upperi, leftj};
        else
            return {-1, -1};
    }
};
int main() {
    vector<vector<int>> a = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    Solution solution;
    vector<int> ans = solution.searchMatrix(a, 60);
    for (int i = 0; i < 2; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}