class Solution {
public:
int mod=1e9+7;
int helper(int ind,int k,int target,vector<vector<int>>&dp,int n){
    if(ind>=n){
        if(target==0){
            return 1;
        }
        return 0;
    }
    if(dp[ind][target]!=-1){
        return dp[ind][target];
    }
    int ans=0;
    for(int i=1;i<=k;i++){
        if(target>=i){
         ans=(ans+helper(ind+1,k,target-i,dp,n))%mod;
       }
    }
    return dp[ind][target]=ans;
}
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return helper(0,k,target,dp,n);
    }
};