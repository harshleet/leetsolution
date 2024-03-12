class Solution {
public:
    int helper(int ind,int buy,int bprice,vector<vector<int>>&dp,vector<int>&prices){
        if(ind>=prices.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        int skip=helper(ind+1,buy,bprice,dp,prices);
        int buys=0,sell=0;
        if(buy==0){
            buys=-prices[ind]+helper(ind+1,1,prices[ind],dp,prices);
        }else if(buy==1){
            sell=prices[ind]+helper(ind+1,0,0,dp,prices);
        }
        return dp[ind][buy]=max({buys,sell,skip});

    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return helper(0,0,0,dp,prices);
    }
};