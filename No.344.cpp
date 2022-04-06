class Solution {
   public:
    void reverseString(vector<char>& s) {
        int lptr = 0;
        int rptr = s.size() - 1;
        while (lptr < rptr) {
            swap(s[rptr], s[lptr]);
            lptr++;
            rptr--;
        }
    }
};
