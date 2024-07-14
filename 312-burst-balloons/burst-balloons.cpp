class Solution {
public:
    int helper(int st,int end,vector<int>&arr,vector<vector<int>>&dp){
        if(st>end){
            return 0;
        }
        if(dp[st][end]!=-1){
            return dp[st][end];
        }
        int maxi=INT_MIN;
        for(int i=st;i<=end;i++){
            int op=arr[st-1]*arr[i]*arr[end+1]+helper(st,i-1,arr,dp)+helper(i+1,end,arr,dp);
            maxi=max(maxi,op);
        }
        return dp[st][end]=maxi;
        
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        temp.push_back(1);
        for(int i=0;i<nums.size();i++){
            temp.push_back(nums[i]);
        }
        temp.push_back(1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
        return helper(1,n,temp,dp);
    }
};