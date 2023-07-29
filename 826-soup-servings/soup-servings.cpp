class Solution {
public:
    double helper(vector<vector<double>>& dp, int sa, int sb, vector<vector<double>>& types) {
        if (sa <= 0 && sb <= 0) {
            return 0.5;
        }
        if (sa <= 0) {
            return 1.0;
        }
        if (sb <= 0) {
            return 0.0;
        }

        if (dp[sa][sb] != -1.0) {
            return dp[sa][sb];
        }

        double ans = 0.0;
        for (int i = 0; i < 4; i++) {
            ans += helper(dp, sa - types[i][0], sb - types[i][1], types);
        }

        return dp[sa][sb] = ans * 0.25;
    }

    double soupServings(int n) {
        if (n >= 5000) return 1.0;

        int maxServe = (n + 24) / 25;
        vector<vector<double>> dp(maxServe + 1, vector<double>(maxServe + 1, -1.0));
        vector<vector<double>> types = {{4, 0}, {3, 1}, {2, 2}, {1, 3}};

        double probability = helper(dp, maxServe, maxServe, types);
        return probability;
    }
};
