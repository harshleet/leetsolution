class Solution {
public:
 int helper(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&dp,int n,int m,vector<vector<int>>&vis){
        if(r<0 || c<0 ||r>=n || c>=m ){
            return 1e8;
        }
       
        if(r==n-1 && c==m-1){
           return grid[r][c];
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
    
        int ri=grid[r][c]+helper(r,c+1,grid,dp,n,m,vis);
        int dow=grid[r][c]+helper(r+1,c,grid,dp,n,m,vis);
        return dp[r][c]=min(ri,dow);

    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        vector<vector<int>>vis(n,vector<int>(m,0));
        return helper(0,0,grid,dp,n,m,vis);
    }
};