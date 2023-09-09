class Solution {
public:
    int helper(int ind, int n, int target, vector<int>& dp, vector<int>& nums) {
       
        if (target == 0) {
            return 1;
        }
    
        if (ind >= n) {
            return 0;
        }
        if (dp[target] != -1) {
            return dp[target];
        }
       
        int take = 0;
        for(int i=0;i<nums.size();i++){
        if (nums[i] <= target) {
            take += helper(ind, n, target - nums[i], dp, nums);
        }
            }
        return dp[target] = take ;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, -1);
        return helper(0, nums.size(), target, dp, nums);
    }
};
