class Solution {
public:
    int helper(int ind,int pre,vector<vector<int>>&dp,vector<int>&nums){
        if(ind>=nums.size()){
            return 0;
        }
        if(dp[ind][pre+1]!=-1){
            return dp[ind][pre+1];
        }
        int nt=helper(ind+1,pre,dp,nums);
        int t=0;
        if(pre==-1 || nums[ind]>nums[pre]){
            t=1+helper(ind+1,ind,dp,nums);
        }
        return dp[ind][pre+1]=max(t,nt);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return helper(0,-1,dp,nums);
    }
};