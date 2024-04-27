#include <vector>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;

    int helper(int z, int o, int lim, int prev, int zero, int one, int limit, vector<vector<vector<vector<int>>>>& dp) {
        if (lim >= limit || z > zero || o > one)
            return 0;
        if (z == zero && o == one)
            return 1;
        if (dp[z][o][prev + 1] [lim]!= -1)
            return dp[z][o][prev + 1][lim];

        int t = 0;
        if (prev == -1 || prev == 0)
            t = helper(z, o + 1, 0, 1, zero, one, limit, dp);
        else
            t = helper(z, o + 1, lim + 1, 1, zero, one, limit, dp);

        int nt = 0;
        if (prev == -1 || prev == 1)
            nt = helper(z + 1, o, 0, 0, zero, one, limit, dp);
        else
            nt = helper(z + 1, o, lim + 1, 0, zero, one, limit, dp);

        return dp[z][o][prev + 1][lim] = (nt + t) % mod;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<vector<int>>>> dp(zero + 1, vector<vector<vector<int>>>(one + 1, vector<vector<int>>(3, vector<int>(limit + 1, -1))));
        return helper(0, 0, 0, -1, zero, one, limit, dp);
    }
};
