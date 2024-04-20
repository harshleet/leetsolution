class Solution {
public:
    vector<int>dr={1,-1,0,0};
    vector<int>dc={0,0,-1,1};
    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<int>>& land,int &rmax,int &cmax,int n,int m){
        vis[r][c]=1;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && land[nr][nc]==1){
                rmax=max(rmax,nr);
               cmax=max(cmax,nc);
                dfs(nr,nc,vis,land,rmax,cmax,n,m);
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m=land[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && land[i][j]==1){
                     int rmax=i;
                     int cmax=j;
                     dfs(i,j,vis,land,rmax,cmax,n,m);
                     ans.push_back({i,j,rmax,cmax});
                }
            }
        }
        return ans;
    }
};