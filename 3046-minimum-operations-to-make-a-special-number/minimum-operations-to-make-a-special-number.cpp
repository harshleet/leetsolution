class Solution {
public:
    int helper(string& num, int ind,  vector<vector<int>>& dp, int mod) {
        if (ind >= num.size()) {
                if (mod % 25 == 0) {
                    return 0;
                }
         
            return 1e8;
        }

        if (dp[ind][mod] != -1) {
            return dp[ind][mod];
        }

        int ntake = 1+helper(num, ind + 1, dp, mod);
        int take = helper(num, ind + 1, dp, (mod * 10 + num[ind] - '0') % 25);

        return dp[ind][mod] = min(ntake, take);
    }

    int minimumOperations(string num) {
        int n = num.size();
        vector<vector<int>> dp(n,vector<int>(26, -1));
   
        return helper(num, 0, dp, 0);
    }
};
