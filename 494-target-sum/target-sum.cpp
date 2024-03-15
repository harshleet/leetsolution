class Solution {
public:
   int helper(int ind,int sum,vector<int>& nums,vector<vector<int>>&dp, int target){
      if(ind>=nums.size()){
          if(sum==target){
            return 1;
          }
          return 0;
      }
      if(dp[ind][sum]!=-1){
        return dp[ind][sum];
      }
      
      int take1=helper(ind+1,sum+nums[ind],nums,dp,target);
      int take2=helper(ind+1,sum-nums[ind],nums,dp,target);
    
      return dp[ind][sum]=take1+take2;
   }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>>dp(nums.size(),vector<int>(target+2004,-1));
        return helper(0,1000,nums,dp,target+1000);
    }
};