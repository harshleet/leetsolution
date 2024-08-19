class Solution {
public:
    int helper(int len,int op,int n,int clen,vector<vector<int>>&dp){
        if(len==n){
            return 0;
        }
        if(len>n){
            return 1e9;
        }
        if(dp[len][clen]!=-1){
            return dp[len][clen];
        }
        int ans=1e9;
        if(clen==0){
            ans=1+helper(len,0,n,len,dp);
        }else{
            ans=min(ans,1+helper(clen+len,-1,n,0,dp));
            ans=min(ans,1+helper(clen+len,0,n,clen,dp));
        }
        return dp[len][clen]=ans;
    }
    int minSteps(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(1,-1,n,0,dp);
    }
};