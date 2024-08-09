class Solution {
public:
int mod=1e9+7;
    int helper(int ind,int target,vector<vector<int>>&types,vector<vector<int>>&dp){
        if(target==0){
            return 1;
        }
        if(ind>=types.size()){
            return 0;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        // int nt=helper(ind+1,target,types,dp);

        int t=0;
        for(int i=0;i<=types[ind][0];i++){
            if(target-(i*types[ind][1])>=0){
              t=(t+helper(ind+1,target-(i*types[ind][1]),types,dp))%mod;
            }
        }
        return dp[ind][target]=t;
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        vector<vector<int>>dp(types.size(),vector<int>(target+1,-1));
        return helper(0,target,types,dp);
    }
};