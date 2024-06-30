class Solution {
public:
    int helper(int ind,int par,int cpar,vector<int>&nums,vector<vector<vector<int>>>&dp){
        if(ind>=nums.size()){
            return 0;
        }
        if(dp[ind][par+1][cpar+1]!=-1){
            return dp[ind][par+1][cpar+1];
        }
        int nt=helper(ind+1,par,cpar,nums,dp);
        int t=0;
        if(par==-1){
            t=1+helper(ind+1,nums[ind]%2,cpar,nums,dp);
        }else if(cpar==-1){
            t=1+helper(ind+1,nums[ind]%2,(par+(nums[ind]%2))%2,nums,dp);
        }else if((par+(nums[ind]%2))%2==cpar){
            t=1+helper(ind+1,nums[ind]%2,cpar,nums,dp);
        }
        return dp[ind][par+1][cpar+1]=max(t,nt);
    }
    int maximumLength(vector<int>& nums) {
        vector<vector<vector<int>>>dp(nums.size(),vector<vector<int>>(3,vector<int>(3,-1)));
        return helper(0,-1,-1,nums,dp);
    }
};