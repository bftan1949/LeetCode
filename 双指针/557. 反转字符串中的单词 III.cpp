class Solution {
   public:
    string reverseWords(string s) {
        int lptr = 0;
        int rptr = 1;
        int i, j;
        while (rptr <= s.size()) {
            if (s[rptr] == ' ' || rptr == s.size()) {
                i = rptr - 1;
                while (lptr < i) {
                    swap(s[i], s[lptr]);
                    i--;
                    lptr++;
                }
                lptr = rptr + 1;
            }
            rptr++;
        }
        return s;
    }
};
