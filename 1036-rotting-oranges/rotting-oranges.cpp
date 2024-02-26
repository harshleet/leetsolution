class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<tuple<int,int,int>>q;
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j,0});
                    vis[i][j]=1;
                    
                }
                if(grid[i][j]==1){
                  c++;
                }
            }
        }
        vector<int>drow={-1,1,0,0};
        vector<int>dcol={0,0,-1,1};
        int cnt=0,maxi=0;
        while(!q.empty()){
            int r=get<0>(q.front());
            int c=get<1>(q.front());
            int t=get<2>(q.front());
            q.pop();
            maxi=max(maxi,t);
            for(int i=0;i<4;i++){
                int nr=r+drow[i];
                int nc=c+dcol[i];
                if(nc>=0 && nr>=0 && nc<m && nr<n && !vis[nr][nc] && grid[nr][nc]==1){
                     vis[nr][nc]=1;
                     q.push({nr,nc,t+1});
                     cnt++;
                }
            }
       
        }
        if(c!=cnt){
            return -1;
        }
        return maxi;
    }
};