class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& grid){
        vis[row][col]=1;
        vector<int>drow={-2,-2,-1,-1,1,1,2,2};
        vector<int>dcol={1,-1,2,-2,2,-2,1,-1};
        for(int i=0;i<8;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow<grid.size() && nrow>=0 && ncol<grid[0].size() && ncol>=0 && !vis[nrow][ncol] && grid[row][col]+1==grid[nrow][ncol]){
                dfs(nrow,ncol,vis,grid);
            }
        }
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        dfs(0,0,vis,grid);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!vis[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
};