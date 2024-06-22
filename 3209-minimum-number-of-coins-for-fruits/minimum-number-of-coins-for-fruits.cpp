class Solution {
public:
    int helper(int ind,vector<int>&prices,vector<int>&dp){
        if(ind>=prices.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int pur=prices[ind];
        int mini=INT_MAX;
        for(int i=ind+1;i<=2*(ind+1);i++){
            mini=min(mini,helper(i,prices,dp));
        }
        
       
        return dp[ind]=pur+mini;
    }
    int minimumCoins(vector<int>& prices) {
        int n=prices.size();
        vector<int>dp(n,-1);
        return helper(0,prices,dp);
    }
};