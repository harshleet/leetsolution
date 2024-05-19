class Solution {
public:
    int helper(int ind1, int ind2, string& s, string& t,
               vector<vector<int>>& dp, int n, int m) {
        if (ind2 >= m) {
            return 1;
        }
        if (ind1 >= n) {
            return 0;
        }
        if (dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }
        int op1 = helper(ind1 + 1, ind2, s, t, dp, n, m);
        int op2 = 0;
        if (s[ind1] == t[ind2]) {
            op2 = helper(ind1 + 1, ind2 + 1, s, t, dp, n, m);
        }
        return dp[ind1][ind2] = op1 + op2;
    }
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<double >> dp(n + 1, vector<double>(m + 1, -1));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (j == 0 ) {
                    dp[i][j] = 1;
                } else if (i == 0) {
                    dp[i][j] = 0;
                } else if (s[i - 1] == t[j - 1]) {
                    dp[i][j]= dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j]=  dp[i - 1][j];
                }
            }
        }
        return int(dp[n][m]);
    }
};