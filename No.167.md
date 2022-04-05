```c++
class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] > target)
                right--;
            else if (numbers[left] + numbers[right] < target)
                left++;
            else
                return vector<int>{left + 1, right + 1};
        }
        return vector<int>{-1, -1};
    }
};
```
## 双指针算法原理
搜索空间如下图所示:
![1](https://pic.leetcode-cn.com/6ee3750f6036a7a6249197e5b640bfc0564153ca1a61c1e35aad51f3a8f9dc5e.jpg)
如果直接暴力搜索,则需要搜索每一个格子,时间复杂度为O(n^2)

1. 双指针可以减少搜索次数, 一次排除掉更多的格子

2. 首先检查(0,7)位置与target大小关系,因为numbers为非递减排序,
所以如果numbers[0]+numbers[7]大于target,说明numbers[i>0]+numbers[7]也必定大于target,因此可以直接排除掉j=7这一列

3. 同理如果小于target,说明numbers[7]以已经是最大的了,所以numbers[0]+numbers[j<7]也必定小于target,因此可以直接排除i=0这一行

4. 经过n步后就可以排除所有的搜索空间，检查完所有的可能性.搜索空间的减小过程如下面动图所示:
![2](https://pic.leetcode-cn.com/9ebb3ff74f0706c3c350b7fb91fea343e54750eb5b6ae6a4a3493421a019922a.gif)


