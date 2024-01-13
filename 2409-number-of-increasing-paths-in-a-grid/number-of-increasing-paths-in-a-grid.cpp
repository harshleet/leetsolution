class Solution {
public:
     int mod=1e9+7;
    int helper(int row,int col,vector<vector<int>>&dp,vector<vector<int>>&grid,vector<vector<int>>&vis){
       
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int drow[]={0,0,1,-1};
        int dcol[]={-1,1,0,0};
         int ans=1;
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow<grid.size() && ncol<grid[0].size() && nrow>=0 && ncol>=0 && grid[nrow][ncol]>grid[row][col] && !vis[nrow][ncol]){
                 vis[nrow][ncol]=1;
               ans=(ans+helper(nrow,ncol,dp,grid,vis))%mod;
                vis[nrow][ncol]=0;
            }
        }
        return dp[row][col]=ans;
    }
    int countPaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                   vis[i][j]=1;
                   ans=(ans+helper(i,j,dp,grid,vis))%mod;
                   vis[i][j]=0;
            }
        }
        return ans;
    }
};