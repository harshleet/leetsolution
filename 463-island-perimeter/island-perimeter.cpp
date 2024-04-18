class Solution {
public:
   vector<int>dr={1,-1,0,0};
   vector<int>dc={0,0,1,-1};
    int dfs(int r,int c,vector<vector<int>>&grid,int n,int m,vector<vector<int>>&vis){
        vis[r][c]=1;
        int ans=0;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
          
            if(nr<0 || nc<0 || nc>=m || nr>=n){
                ans++;
            }
            if(nr>=0 && nc>=0 && nc<m && nr<n &&  grid[nr][nc]==0){
                ans++;
            }
            if(nr>=0 && nc>=0 && nc<m && nr<n && !vis[nr][nc] && grid[nr][nc]==1){
                ans+=dfs(nr,nc,grid,n,m,vis);
            }
        }
        
        return ans;

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                   ans+=dfs(i,j,grid,n,m,vis);
                  }
            }
        }
        return ans;
    }
};