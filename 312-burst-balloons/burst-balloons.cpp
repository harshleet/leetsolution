class Solution {
public:
    int helper(int st,int end,vector<int>&nums,vector<vector<int>>&dp){
        if(st>end){
            return 0;
        }
        
        if(dp[st][end]!=-1){
            return dp[st][end];
        }
        int mini=INT_MIN;
        for(int i=st;i<=end;i++){
            int l=helper(st,i-1,nums,dp);
            int r=helper(i+1,end,nums,dp);
            int ops=nums[i]*nums[st-1]*nums[end+1];
            
            mini=max(mini,l+r+ops);
            
        }
        return  dp[st][end]=mini;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
         vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
         nums.push_back(1);
         nums.insert(nums.begin(),1);
        return helper(1,n,nums,dp);
    }
};