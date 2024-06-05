class Solution {
public:
int mod=1e9+7;
    int helper(int pk,int de,vector<vector<int>>&dp){
        if(pk==0 && de==0){
            return 1;
        }
       if(dp[pk][de]!=-1){
        return dp[pk][de];
       }
        long long int val=0;
        if(pk>0){
            long long int v=pk;
            val=(v*(helper(pk-1,de,dp))%mod)%mod;
        }
       long long  int val2=0;
        if(de>pk){
           long long int mind=de-pk;
            val2=(mind*(helper(pk,de-1,dp))%mod)%mod;
        }
        return dp[pk][de]=(val+val2)%mod;
    }
    int countOrders(int n) {
        //this ill try to sue

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helper(n,n,dp);
    }
};