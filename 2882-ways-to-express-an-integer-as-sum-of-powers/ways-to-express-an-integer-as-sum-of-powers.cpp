class Solution {
public:
int mod=(1e9+7);
    int helper(int ind,int n,vector<vector<int>>&dp,int x){
        if(n==0){
            return 1;
        }
        if(n<0 || ind>n){
            return 0;
        }
        if(dp[ind][n]!=-1){
            return dp[ind][n];
        }
        int nt=helper(ind+1,n,dp,x);
        int t=0;
        if(n-pow(ind,x)>=0){
            t=helper(ind+1,n-pow(ind,x),dp,x);
        }
        return dp[ind][n]=(t+nt)%mod;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(1,n,dp,x);
    }
};