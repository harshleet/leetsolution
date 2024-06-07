class Solution {
public:
    int helper(int ind, int target, vector<int>& nums,
               vector<vector<int>>& dp) {
        if (ind >= nums.size()) {
            if (target == 0) {
                return 1;
            }
            return 0;
        }
        if(dp[ind][target+1000]!=-1){
            return dp[ind][target+1000];
        }
        int ne = helper(ind + 1, target + nums[ind], nums, dp);
        int po = helper(ind + 1, target - nums[ind], nums, dp);
       
        return dp[ind][target+1000]=ne + po;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int>(20001, -1));
        return helper(0, target, nums, dp);
    }
};