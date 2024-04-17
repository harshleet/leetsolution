class Solution {
public:
   int helper(int n,vector<int>&dp){
        if(n==0){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int val=0;
        for(int i=1;i<=n;i++){
            val=max(val,i*helper(n-i,dp));
        }
        return dp[n]=val;
   }
    int integerBreak(int n) {
        // always the first intution regarding tht it has the recursion but to
        // keep one thing in mind it must be linear dp easy same as the decode
        // ways
        vector<int>dp(n+1,-1);
        int val=0;
        for(int i=1;i<n;i++){
            val=max(val,i*helper(n-i,dp));
        }
        return val;
    }
};