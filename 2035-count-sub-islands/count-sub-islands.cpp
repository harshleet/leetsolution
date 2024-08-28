class Solution {
public:
    vector<int>dr={1,-1,0,0};
    vector<int>dc={0,0,1,-1};
    void dfs(int r,int c,vector<vector<int>>& grid1, vector<vector<int>>& grid2,bool &f,vector<vector<int>>&vis){
        int n=grid1.size(),m=grid1[0].size();
        vis[r][c]=1;
        if(grid1[r][c]==0){
            f&=false;
        }

        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid2[nr][nc]==1){
                dfs(nr,nc,grid1,grid2,f,vis);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size(),m=grid1[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool f=true;
                if(grid2[i][j]==1 && !vis[i][j]){
                    dfs(i,j,grid1,grid2,f,vis);
                    if(f==true){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};