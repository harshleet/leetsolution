class Solution {
public:
int mod=1e9+7;
    int helper(int ind,int pre,int n,vector<vector<int>>&dp){
        if(ind==n){
            if(pre==0){
              return 1;
            }
            return 0;
        }
        if(ind>n){
            return 0;
        }
        if(dp[ind][pre]!=-1){
            return dp[ind][pre];
        }
        int w1=0;
        if(pre==0){
          w1=(w1+helper(ind+1,0,n,dp))%mod;
        }
        
        if(pre==1 ||pre==2){
            w1=(w1+helper(ind+2,0,n,dp))%mod;
            // w1=(w1+helper(ind+2,0,n,dp))%mod;
        }else if(pre==0){
            w1=(w1+helper(ind+1,1,n,dp))%mod;
            w1=(w1+helper(ind+1,2,n,dp))%mod;
        }
         
        if(pre==1 || pre==2){
            w1=(w1+helper(ind+1,1,n,dp))%mod;
        }else if(pre==0){
            w1=(w1+helper(ind+2,0,n,dp))%mod;
        }
      
       return dp[ind][pre]=w1;
    }
    int numTilings(int n) {
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return helper(0,0,n,dp);
    }
};