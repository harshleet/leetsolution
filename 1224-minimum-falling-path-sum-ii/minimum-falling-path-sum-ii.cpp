class Solution {
public:
    int helper(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&dp){
       if(r>=grid.size()){
        return 0;
       }
       if(dp[r][c+1]!=-1){
        return dp[r][c+1];
       }
       int mini=INT_MAX;
       for(int i=0;i<grid[0].size();i++){
            if(c==-1 || i!=c){
                mini=min(mini,grid[r][i]+helper(r+1,i,grid,dp));
            }
       }
       return dp[r][c+1]= mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int r= grid.size(),c=grid[0].size();
        vector<vector<int>>dp(r,vector<int>(c+1,-1));
        return helper(0,-1,grid,dp);
    }
};