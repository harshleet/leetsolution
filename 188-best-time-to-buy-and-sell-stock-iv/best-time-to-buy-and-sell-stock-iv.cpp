class Solution {
public:
   int helper(int ind,vector<int>&prices, vector<vector<vector<int>>>&dp,bool pur,int lim){
        if(ind>=prices.size() || lim==0){
            if(pur==0){
                return 0;
            }
            return -1e8;
        }
        if(dp[ind][pur][lim]!=-1){
            return dp[ind][pur][lim];
        }
       
        int ntake=helper(ind+1,prices,dp,pur,lim);
        
        if(pur==1){
              return dp[ind][pur][lim]=max(ntake,prices[ind]+helper(ind+1,prices,dp,0,lim-1));
        }
        return dp[ind][pur][lim]=max(ntake,-prices[ind]+helper(ind+1,prices,dp,1,lim));
    }
    int maxProfit(int k, vector<int>& prices) {
          int n=prices.size();
          int lim=k;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(lim+1,-1)));
        return helper(0,prices,dp,0,lim);
    }
};