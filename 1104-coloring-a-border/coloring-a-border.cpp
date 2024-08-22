class Solution {
public:
vector<int>dr={1,-1,0,0};
    vector<int>dc={0,0,1,-1};
    void helper(int r,int c,vector<vector<int>>&vis,vector<vector<int>>&grid,int color,int pcol){
      
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr<0 || nc<0 || nr>=grid.size() || nc>=grid[0].size() || (grid[nr][nc]!=pcol && !vis[nr][nc])){
                grid[r][c]=color;
            }
            if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && grid[nr][nc]==pcol && !vis[nr][nc]){
                helper(nr,nc,vis,grid,color,pcol);
            }
        }
        
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
       
         helper(row,col,vis,grid,color,grid[row][col]);
         
        return grid;
    }
};