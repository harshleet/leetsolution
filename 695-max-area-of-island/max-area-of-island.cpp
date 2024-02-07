class Solution {
public:
   int dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid,int n,int m){
       vis[row][col]=1;
       int dr[]={1,-1,0,0};
       int dc[]={0,0,-1,1};
       int ans=1;
       for(int i=0;i<4;i++){
           int nrow=row+dr[i];
           int ncol=col+dc[i];
           if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
               ans+=dfs(nrow,ncol,vis,grid,n,m);
           }
       }
       return ans;
   }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
         vector<vector<int>>vis(n,vector<int>(m,0));
         int maxi=0;
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(grid[i][j]==1 && !vis[i][j]){
                    maxi=max(maxi, dfs(i,j,vis,grid,n,m));
                 }
             }
         } 
         return maxi;
    }
};