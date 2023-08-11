class Solution {
public:
   int rec(vector<int>&coins, vector<vector<int>>&dp,int amount,int ind){
        
         if(ind==0){
             if(amount%coins[0]==0){
                 return 1;
             }
             return 0;
             
         }
         if(dp[ind][amount]!=-1){
             return dp[ind][amount];
         }
         int ntake=rec(coins,dp,amount,ind-1);
         int take=0;
         if(coins[ind]<=amount){
             take=rec(coins,dp,amount-coins[ind],ind);
         }
         return dp[ind][amount]=ntake+take;
     }
    int change(int amount, vector<int>& coins) {
         vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
          if(rec(coins,dp,amount,coins.size()-1)==1e9)
              return -1;
        else 
            return rec(coins,dp,amount,coins.size()-1);
    }
};