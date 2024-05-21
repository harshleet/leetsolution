class Solution {
public:
    bool isPalindrome(int st, int end, string& s, vector<vector<int>>& pal) {
        while (st < end) {
            if (s[st] != s[end]) {
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
    int helper(int ind, string& s, int n, vector<int>& dp,
               vector<vector<int>>& pal) {
        if (ind >= n) {
            return -1;
        }
        if (dp[ind] != -1) {
            return dp[ind];
        }
        int mini = INT_MAX;
        for (int i = 1; i <= n - ind; i++) {

            if (isPalindrome(ind, ind + i - 1, s, pal)) {
                mini = min(mini, 1 + helper(ind + i, s, n, dp, pal));
            }
        }
        return dp[ind] = mini;
    }
    int minCut(string s) {
        vector<int> dp(s.size(), -1);
        vector<vector<int>> pal(s.size(), vector<int>(s.size(), -1));
        // for (int i = 0; i < s.size(); i++) {
        //     pal[i][i] = 1;
        // }
        return helper(0, s, s.size(), dp, pal);
    }
};