class Solution {
public:
   bool helper(int ind,int sum,int target,vector<int>&nums,vector<vector<int>>&dp){
    if(sum==target){
            return true;
     }
    if(ind>=nums.size() || sum>target){
        return false;
    }
    if(dp[ind][sum]!=-1){
        return dp[ind][sum];
    }
      int nt=helper(ind+1,sum,target,nums,dp);
      int t=helper(ind+1,sum+nums[ind],target,nums,dp);

      return dp[ind][sum]=nt|t;

   }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1){
            return false;
        }
        vector<vector<int>>dp(nums.size(),vector<int>((sum/2)+1,-1));
        return helper(0,0,sum/2,nums,dp);
    }
};