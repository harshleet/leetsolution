class Solution {
public:
   vector<int>dr={-1,1,0};
   vector<int>dc={1,1,1};
    int helper(int r,int c,vector<vector<int>>&dp,int n,int m,vector<vector<int>>&grid){
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int maxi=0;

        for(int i=0;i<3;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[r][c]<grid[nr][nc]){
                maxi=max(maxi,1+helper(nr,nc,dp,n,m,grid));
            }
        }
        return dp[r][c]=maxi;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int maxi=0;
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));

        for(int i=0;i<n;i++){
            
                maxi=max(maxi,helper(i,0,dp,n,m,grid));
            
        }
        return maxi;
    }
};