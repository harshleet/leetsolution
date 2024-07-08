class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        //very good qustion

        int n=grid.size();
        queue<tuple<int,int,int>>q;
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<int>dc={0,0,1,-1};
        vector<int>dr={1,-1,0,0};

        vector<vector<int>>dis(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j,0});
                    vis[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            auto it=q.front();
            int r=get<0>(it);
            int c=get<1>(it);
            int dist=get<2>(it);
            q.pop();

            dis[r][c]=dist;

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nc>=0 && nr<n && nc<n && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({nr,nc,dist+1});
                }
            }
        }

        vector<vector<int>>dis2(n,vector<int>(n,0));
        priority_queue<tuple<int,int,int>>pq;

        pq.push({dis[0][0],0,0});

        while(!pq.empty()){
            auto [dist,r,c]=pq.top();
            pq.pop();

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nc>=0 && nr<n && nc<n){
                    int maxi=min(dist,dis[nr][nc]);
                    if(dis2[nr][nc]<maxi){
                        dis2[nr][nc]=maxi;
                        pq.push({maxi,nr,nc});
                    }
                }
            }
        }
        return dis2[n-1][n-1];
    }
};