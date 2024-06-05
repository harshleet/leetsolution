class Solution {
public:
    int helper(int ind, vector<vector<int>>& dp, vector<int>& nums, int f) {
        if (ind >= nums.size()) {
            return 0;
        }
        if (dp[ind][f] != -1) {
            return dp[ind][f];
        }
        int nt = helper(ind + 1, dp, nums,f);
        int t = 0;
        if (ind == 0) {
            t=nums[ind] + helper(ind + 2, dp, nums,1);
        }else if(ind==nums.size()-1 && f==1 ){
            t=0;
        }else{
            t=nums[ind]+helper(ind+2,dp,nums,f);
        }
        return dp[ind][f] = max(t, nt);
    }
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, -1));
        return helper(0, dp, nums,0);
    }
};