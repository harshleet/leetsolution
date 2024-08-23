class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>>vis(n,vector<vector<int>>(m,vector<int>(k+1,0)));

        queue<vector<int>>q;
        q.push({0,0,k,0});
     

        vis[0][0][k]=1;
        vector<int>dr={1,-1,0,0};
        vector<int>dc={0,0,-1,1};
        int mini=1e9;
        while(!q.empty()){
            vector<int>t=q.front();
            q.pop();

            if(t[0]==n-1 && t[1]==m-1){
                mini=min(mini,t[3]);
            }
            for(int i=0;i<4;i++){
                int nr=t[0]+dr[i];
                int nc=t[1]+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m ){
                    if(grid[nr][nc]==0 && !vis[nr][nc][t[2]]){
                       vis[nr][nc][t[2]]=1;
                        q.push({nr,nc,t[2],t[3]+1});
                    }else if(grid[nr][nc]==1 && t[2]>0 && !vis[nr][nc][t[2]-1]){
                        vis[nr][nc][t[2]-1]=1;
                        q.push({nr,nc,t[2]-1,t[3]+1});
                    }
                }
            }
        }
        if(mini==1e9){
            return -1;
        }
        return mini;
    }
};