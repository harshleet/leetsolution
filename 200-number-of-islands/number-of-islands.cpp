class Solution {
public:

    void dfs(int row,int col,vector<vector<int>>&vis,int& n,int& m,vector<vector<char>>& grid){
       vis[row][col]=1;
       int drow[]={1,-1,0,0};
       int dcol[]={0,0,-1,1};

       for(int i=0;i<4;i++){
           int nrow=row+drow[i];
           int ncol=col+dcol[i];

           if(ncol>=0 && nrow>=0 && nrow<n && ncol<m &&!vis[nrow][ncol] && grid[nrow][ncol]=='1' ){
               dfs(nrow,ncol,vis,n,m,grid);
           }
       }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
          int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    c++;
                    dfs(i,j,vis,n,m,grid);
                }
            }
        }
        return c;
    }
};