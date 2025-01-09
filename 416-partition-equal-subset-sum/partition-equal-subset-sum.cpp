class Solution {
public:
    bool helper(int ind,int sum,vector<vector<int>>&dp,vector<int>&nums,int target){
        if(sum==target){
            return true;
        }
        if(ind>=nums.size()){
            return false;
        }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }

        bool nt=helper(ind+1,sum,dp,nums,target);
        bool t=false;
        if(sum+nums[ind]<=target){
            t=helper(ind+1,sum+nums[ind],dp,nums,target);
        }
        return dp[ind][sum]=nt|t; 


    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),target=accumulate(nums.begin(),nums.end(),0);
        if(target%2!=0){
            return false;
        }
        vector<vector<int>>dp(n,vector<int>((target/2)+1,-1));
        return helper(0,0,dp,nums,target/2);
    }
};