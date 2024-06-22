class Solution {
public:
    int helper(int ind,int p,vector<int>&prices,vector<vector<int>>&dp){
        if(ind>=prices.size()){
            return 0;
        }
        if(dp[ind][p]!=-1){
            return dp[ind][p];
        }
        int pur=prices[ind]+helper(ind+1,ind+1,prices,dp);
        int npur=INT_MAX;
        if(p>0){
            npur=helper(ind+1,p-1,prices,dp);
        }
        return dp[ind][p]=min(pur,npur);
    }
    int minimumCoins(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(0,0,prices,dp);
    }
};