class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        int size_1 = s1.size(), size_2 = s2.size();
        int left = 0, right = 0, flag[26] = {0};

        // 对s1每个字符进行统计
        for (auto it = s1.begin(); it < s1.end(); it++)
            flag[(*it) - 'a']++;

        while (right < size_2) {
            flag[s2[right] - 'a']--;
            while (flag[s2[right] - 'a'] < 0) {
                flag[s2[left] - 'a']++;
                left++;
            }
            if (right - left + 1 == size_1)
                return true;
            right++;
        }
        return false;
    }
};
