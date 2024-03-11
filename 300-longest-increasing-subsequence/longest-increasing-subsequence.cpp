class Solution {
public:
    int helper(int ind,int prev,vector<int>& nums,vector<vector<int>>&dp){
        if(ind>=nums.size()){
            return 0;
        }
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        int ntake=helper(ind+1,prev,nums,dp);
        int take=0;
        if(prev==-1|| nums[prev]<nums[ind]){
               take=1+helper(ind+1,ind,nums,dp);
        }
        return dp[ind][prev+1]=max(ntake,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(0,-1,nums,dp);
    }
};