class Solution {
public:
 int dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&vis){
        vis[i][j]=1;

        int dcol[]={0,0,-1,1};
        int drow[]={1,-1,0,0};
         int ans=1;
        for(int k=0;k<4;k++){
            int nrow=i+drow[k];
            int ncol=j+dcol[k];

            if(nrow>=0 && ncol>=0 && nrow<grid.size() && ncol<grid[0].size() && grid[nrow][ncol]==1 && vis[nrow][ncol] == 0 ){
                ans+=dfs(nrow,ncol,grid,vis);
            }
        }
        return ans;
       
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int c=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(vis[i][j]==0 && grid[i][j]==1 ){
                    c=max(c,dfs(i,j,grid,vis));
                }
            }
        }
        return c;
    }
};