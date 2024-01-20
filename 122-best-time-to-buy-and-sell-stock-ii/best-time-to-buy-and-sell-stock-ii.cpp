class Solution {
public:
    int helper(int ind,vector<int>&prices,vector<vector<int>>&dp,bool pur){
        if(ind>=prices.size()){
            if(pur==0){
                return 0;
            }
            return -1e8;
        }
        if(dp[ind][pur]!=-1){
            return dp[ind][pur];
        }
       
        int ntake=helper(ind+1,prices,dp,pur);
        
        if(pur==1){
              return dp[ind][pur]=max(ntake,prices[ind]+helper(ind+1,prices,dp,0));
        }
        return dp[ind][pur]=max(ntake,-prices[ind]+helper(ind+1,prices,dp,1));
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(0,prices,dp,0);
    }
};