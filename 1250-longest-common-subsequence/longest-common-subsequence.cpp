class Solution {
public:
    int f(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ntake = max(f(s1, s2, i - 1, j, dp), f(s1, s2, i, j - 1, dp));
        int take = 0;
        if (s1[i] == s2[j]) {
            take = 1 + f(s1, s2, i - 1, j - 1, dp);
        }
        return dp[i][j] = max(ntake, take);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }
};