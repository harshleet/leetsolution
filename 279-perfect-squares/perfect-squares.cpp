
class Solution {
public:
   int helper(int n,vector<int>&dp){
       if(n<=0){
           return 0;
       }
       if(dp[n]!=-1){
           return dp[n];
       }
       int mini=1e8;
       for(int i=1;i*i<=n;i++){
          int val=1+helper(n-(i*i),dp);
          mini=min(mini,val);
       }
       return dp[n]=mini;
   }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};