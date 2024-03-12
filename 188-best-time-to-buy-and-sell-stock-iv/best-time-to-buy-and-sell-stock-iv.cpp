class Solution {
public:
    int helper(int ind,int buy,int lim, vector<int>& prices,vector<vector<vector<int>>>& dp,int k){
        if(ind>=prices.size() || lim==0){
            return 0;
        }
        if(dp[ind][buy][lim]!=-1){
            return dp[ind][buy][lim];
        }
        int skip=helper(ind+1,buy,lim,prices,dp,k);
        int buys=INT_MIN,sell=INT_MIN;
        if(buy==0){
              buys=-prices[ind]+helper(ind+1,1,lim,prices,dp,k);
        }else if(buy==1){
            sell=prices[ind]+helper(ind+1,0,lim-1,prices,dp,k);
        }
        return dp[ind][buy][lim]=max({skip,sell,buys});
    }
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return helper(0,0,k,prices,dp,k);
    }
};