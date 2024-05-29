
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>man(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
           queue<tuple<int, int, int>> q;
                for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                      q.push({0,i,j});
                      vis[i][j]=1;
                }
            }
        }
        vector<int>dr={1,-1,0,0};
        vector<int>dc={0,0,1,-1};
        while(!q.empty()){
            int dis=get<0>(q.front());
            int r=get<1>(q.front());
            int c=get<2>(q.front());
            q.pop();
           for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc]){
                    man[nr][nc]=dis+1;
                    vis[nr][nc]=1;
                    q.push({dis+1,nr,nc});
                }
            }

        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<man[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<vector<int>>dist(n,vector<int>(m,0));
        priority_queue<tuple<int,int,int>>pq;
        pq.push({man[0][0],0,0});
        while(!pq.empty()){
             int dis=get<0>(pq.top());
            int r=get<1>(pq.top());
            int c=get<2>(pq.top());
            pq.pop();
            // cout<<r<<" "<<c<<" "<<dis<<endl;
            if(r==n-1 && c==m-1){
                return dis;
            }
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m ){
                    int mini=min(dis,man[nr][nc]);
                    if(dist[nr][nc]<mini){
                        dist[nr][nc]=mini;
                        pq.push({mini,nr,nc});
                    }
                }
            }

        }
        
        return 0;

    }
};