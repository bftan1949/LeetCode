class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int left = 0, right = 0, length = 0, max_length = 0;
        while (right < s.size()) {
            length++;
            while (set.count(s[right]) != 0) {
                set.erase(s[left]);
                left++;
                length--;
            }
            set.insert(s[right]);
            if (length > max_length)
                max_length = length;
            right++;
        }
        return max_length;
    }
};
