class Solution {
public:
     int rec(vector<int>&coins, vector<vector<int>>&dp,int amount,int ind){
        
         if(ind==0){
             if(amount%coins[0]==0){
                 return amount/coins[0];
             }
             return 1e9;
             
         }
         if(dp[ind][amount]!=-1){
             return dp[ind][amount];
         }
         int ntake=rec(coins,dp,amount,ind-1);
         int take=INT_MAX;
         if(coins[ind]<=amount){
             take= 1+rec(coins,dp,amount-coins[ind],ind);
         }
         return dp[ind][amount]=min(ntake,take);
     }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        if(rec(coins,dp,amount,coins.size()-1)==1e9)
              return -1;
        else 
            return rec(coins,dp,amount,coins.size()-1);
    }
};