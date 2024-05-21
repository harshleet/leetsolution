class Solution {
public:
    bool isPalindrome(string& s) {
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[s.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
    void helper(int ind, vector<vector<string>>& ans, string s,
                vector<string>& ds) {
        if (ind >= s.size()) {
            ans.push_back(ds);
            return;
        }
        for (int i = 1; i <= s.size() - ind; i++) {
            string sub = s.substr(ind, i);
            if (isPalindrome(sub)) {
                ds.push_back(sub);
                helper(ind + i , ans, s, ds);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        vector<vector<string>> ans;
        helper(0, ans, s, ds);
        return ans;
    }
};