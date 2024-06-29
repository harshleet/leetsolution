class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,1e9));
        for(int i=0;i<coins.size();i++){
            dp[i][0]=0;
        }
        for(int sum=1;sum<=amount;sum++){
            if(sum%coins[0]==0){
                dp[0][sum]=sum/coins[0];
            }
        }
        for(int ind=1;ind<coins.size();ind++){
            for(int sum=1;sum<=amount;sum++){
                int nt=dp[ind-1][sum];
                int t=1e9;
                if(sum>=coins[ind]){
                    t=1+dp[ind][sum-coins[ind]];
                }
                dp[ind][sum]=min(t,nt);
            }
        }
        if(dp[coins.size()-1][amount]==1e9){
            return -1;
        }
        return dp[coins.size()-1][amount];
    }
};