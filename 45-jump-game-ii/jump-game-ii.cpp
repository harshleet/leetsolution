class Solution {
public:
    int helper(int ind,vector<int>&nums,vector<int>&dp){
         if(ind==nums.size()-1){
            return 0;
         }
         if(dp[ind]!=-1){
            return dp[ind];
         }
        int mini=1e8;
        for(int i=ind+1;i<=ind+nums[ind];i++){
           
            if(i<nums.size()){
              mini=min(mini,1+helper(i,nums,dp));
            }
        }
        return dp[ind]=mini;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return helper(0,nums,dp);
    }
};