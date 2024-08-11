class Solution {
public:
    vector<int>dr={1,-1,0,0};
    vector<int>dc={0,0,-1,1};
    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<int>>&grid,int n,int m){
        vis[r][c]=1;

        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]==1){
                dfs(nr,nc,vis,grid,n,m);
            }
        }

    }
    int minDays(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    dfs(i,j,vis,grid,n,m);
                    ans++;
                }
            }
        }
        // cout<<ans<<endl;
        if(ans>1 || ans==0){
            return 0;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==1){
                    grid[i][j]=0;
                    vector<vector<int>>vis2(n,vector<int>(m,0));
                    int cnt=0;
                    for(int k=0;k<n;k++){
                        for(int l=0;l<m;l++){
                            if(!vis2[k][l] && grid[k][l]==1){
                                dfs(k,l,vis2,grid,n,m);
                                cnt++;
                            }
                        }
                    }
                    if(cnt>1 || cnt==0){
                        return 1;
                    }
                     grid[i][j]=1;
                }

            }
        }
        return 2;
    }
};