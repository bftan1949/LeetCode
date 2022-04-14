class Solution {
   private:
    vector<string> temp;

   public:
    vector<string> letterCasePermutation(string s) {
        dfs(s, 0);
        return temp;
    }
    void dfs(string s, int i) {
        if (i == s.size()) {
            temp.push_back(s);
            return;
        }
        if (!(s[i] - '0' <= 9 && s[i] - '0' >= 0)) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] -= 32;
                dfs(s, i + 1);
                s[i] += 32;
                dfs(s, i + 1);
            } else {
                s[i] += 32;
                dfs(s, i + 1);
                s[i] -= 32;
                dfs(s, i + 1);
            }
        } else
            dfs(s, i + 1);
    }
};
