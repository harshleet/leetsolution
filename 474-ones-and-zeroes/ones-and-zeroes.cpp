class Solution {
public:
    int calfreq(string& s) {
        int c = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                c++;
            }
        }
        return c;
    }

    int helper(vector<string>& strs, vector<vector<vector<int>>>& dp, int m, int n, int ind, vector<int>& ones, vector<int>& zero) {
        if (ind >= strs.size() || (m <= 0 && n <= 0)) {
            return 0;
        }

        if (dp[ind][m][n] != -1) {
            return dp[ind][m][n];
        }

        int ntake = helper(strs, dp, m, n, ind + 1, ones, zero);
        int take = 0;
        if (zero[ind] <= m && ones[ind] <= n) {
            take = 1 + helper(strs, dp, m - zero[ind], n - ones[ind], ind + 1, ones, zero);
        }

        return dp[ind][m][n] = max(ntake, take);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        vector<int> ones(strs.size());
        vector<int> zero(strs.size());
        for (int i = 0; i < strs.size(); i++) {
            int a = calfreq(strs[i]);
            ones[i] = a;
            zero[i] = strs[i].size() - a;
        }
        return helper(strs, dp, m, n, 0, ones, zero);
    }
};
