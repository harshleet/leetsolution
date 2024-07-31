class Solution {
public:
    int helper(int ind,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(amount==0){
            return 0;
        }
        if(ind>=coins.size()){
            return 1e9;
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        // int nt=helper(ind+1,amount,coins,dp);
        int t=1e9;
        for(int i=0;i<=amount/coins[ind];i++){
            t=min(t,i+helper(ind+1,amount-coins[ind]*i,coins,dp));
        }
        return dp[ind][amount]=t;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int val=helper(0,amount,coins,dp);
        if(val>=1e9){
            return -1;
        }
        return val;
    }
};