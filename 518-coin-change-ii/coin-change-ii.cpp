class Solution {
public:

int helper(int amo,int ind,vector<int>&coins,vector<vector<int>>&dp){
	if(amo==0){
		return 1;
	}
	if(ind>=coins.size()){
		return 0;
	}
    if(dp[ind][amo]!=-1){
        return dp[ind][amo];
    }
	int ntake=helper(amo,ind+1,coins,dp);
	int t=0;
	if(amo>=coins[ind]){
       t=helper(amo-coins[ind],ind,coins,dp);
	}
         
	return dp[ind][amo]=ntake+t;
}
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return helper(amount,0,coins,dp);
    }
};