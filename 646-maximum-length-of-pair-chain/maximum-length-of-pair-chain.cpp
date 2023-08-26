class Solution {
public:
    int helper(int ind, int prev, vector<vector<int>>& dp, vector<vector<int>>& pairs) {
        if (ind == pairs.size()) {
            return 0;
        }
        if (dp[ind][prev + 1] != -1) {
            return dp[ind][prev + 1];
        }

        int ntake = helper(ind + 1, prev, dp, pairs);
        int take = -1e9;
        if (prev==-1||pairs[prev][1] < pairs[ind][0]) {
        
            take = 1 + helper(ind + 1, ind, dp, pairs);
        }
        return dp[ind][prev + 1] = max(take, ntake);
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<vector<int>> dp(pairs.size(), vector<int>(pairs.size()+1, -1));
        sort(pairs.begin(),pairs.end());
        return helper(0, -1, dp, pairs);
    }
};
