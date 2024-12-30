class Solution {
public:
int mod=1e9+7;
    int helper(int len,int low, int high, int zero, int one,vector<int>&dp){
        if(dp[len]!=-1){
            return dp[len];
        }
        int ans=0;

        if(len+one<=high){
            ans=(ans+helper(len+one,low,high,one,zero,dp))%mod;
        }
        if(len+zero<=high){
            ans=(ans+helper(len+zero,low,high,one,zero,dp))%mod;
        }
        if(len+one>=low && len+one<=high){
            ans=(ans+1)%mod;
        }
        if(len+zero>=low && len+zero<=high){
           ans=(ans+ 1)%mod;
        }
        return dp[len]=ans;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int>dp(high+1,-1);
        return helper(0,low,high,one,zero,dp);
    }
};