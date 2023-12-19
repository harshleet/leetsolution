class Solution {
public:
    int mod = 1e9 + 7;

    int helper(int n, string &s, int k, vector<int> &dp, int ind) {
        if (ind == n) {
            return 1;
        }
        if (ind > n) {
            return 0;
        }
        if (dp[ind] != -1) {
            return dp[ind];
        }

        int ways = 0;
        for (int i = 1; i <= s.length() - ind; i++) {
            string sub = s.substr(ind, i);
            long long val = stoll(sub);
            if (val >= 1 && val <= k) {
                ways = (ways + helper(n, s, k, dp, ind + i)) % mod;
            } else {
                break;
            }
        }
        return dp[ind] = ways;
    }

    int numberOfArrays(string s, int k) {
        vector<int> dp(s.length(), -1);
        return helper(s.length(), s, k, dp, 0);
    }
};
