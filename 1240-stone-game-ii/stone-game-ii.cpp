class Solution {
public:
    int helper(int ind, int m, int t, vector<int>& piles, int n, vector<int>& pre,vector<vector<vector<int>>>&dp) {
        if (ind >= n) {
            return 0;
        }

        if(dp[ind][m][t]!=-1){
            return dp[ind][m][t];
        }
        if (t == 0) {
            int val=0;
            for (int i = ind; i < min(2 * m + ind, n); i++) {
                val = max(val,pre[i+1] - pre[ind] + helper(i+1, max(m,i-ind+1), 1, piles, n, pre,dp));
            }
            return val;
        }
            int val=INT_MAX;
            for (int i = ind; i < min(2 * m + ind, n); i++) {
                val =min(val, helper(i+1, max(m,i-ind+1), 0, piles, n, pre,dp));
            }
            return dp[ind][m][t]=val;
    }
    int stoneGameII(vector<int>& piles) {
        vector<int> pre(piles.size() + 1, 0);
        for (int i = 0; i < piles.size(); i++) {
            pre[i + 1] = pre[i] + piles[i];
        }
        vector<vector<vector<int>>>dp(piles.size(),vector<vector<int>>(2*piles.size()+1,vector<int>(2,-1)));
        return helper(0, 1, 0, piles, piles.size(), pre,dp);
    }
};