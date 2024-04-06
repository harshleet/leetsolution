class Solution {
public:
    int helper(int ind, vector<vector<int>>& pref, vector<int>& nums, int k, vector<int>& dp) {
        if (ind >= nums.size()) {
            return 0;
        }
        if (dp[ind] != -1) {
            return dp[ind];
        }

        // int nb = helper(ind + 1, pref, nums, k, dp);
        int b = INT_MAX;
        for (int i = ind; i < nums.size(); i++) {
            b = min(b,pref[ind][i] + k + helper(i + 1, pref, nums, k, dp));
        }

        return dp[ind]=b;
    }
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> pref(n + 1, vector<int>(n));

        for (int i = 0; i < n; i++) {
            map<int, int> m;
            int su = 0;
            for (int j = i; j < n; j++) {
                m[nums[j]]++;

                if (m[nums[j]] == 2) {
                    su += 2;
                } else if (m[nums[j]] > 2) {
                    su++;
                }

                pref[i][j] = su;
            }
            
        }
        vector<int> dp(n, -1);
        return helper(0, pref, nums, k, dp);
    }
};