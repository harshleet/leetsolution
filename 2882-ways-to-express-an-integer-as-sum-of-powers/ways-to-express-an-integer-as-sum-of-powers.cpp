class Solution {
public:
int mod=1e9+7;
    int helper(int n,int x,int ind,vector<vector<int>>&dp){
        
        if(n==0){
            return 1;
        }
        if(n<0|| n-pow(ind,x)<0){
            return 0;
        }
        if(dp[ind][n]!=-1){
            return dp[ind][n];
        }
        int ntake=helper(n,x,ind+1,dp);
        int take=0;
        if(n-pow(ind,x)>=0){
            take=helper(n-pow(ind,x),x,ind+1,dp);
        }
        return dp[ind][n]=(take+ntake)%mod;
    }
    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return  helper(n,x,1,dp);
    }
};