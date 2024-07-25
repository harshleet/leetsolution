class Solution {
public:
    int helper(int ind,int buy,vector<int>&prices,vector<vector<int>>&dp){
        if(ind>=prices.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        int nop=helper(ind+1,buy,prices,dp);
        int b=0,sell=0;
        if(buy==0){
            b=-prices[ind]+helper(ind+1,1,prices,dp);
        }else{
            sell=prices[ind]+helper(ind+2,0,prices,dp);
        }
        return dp[ind][buy]=max({nop,b,sell});
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(0,0,prices,dp);
    }
};