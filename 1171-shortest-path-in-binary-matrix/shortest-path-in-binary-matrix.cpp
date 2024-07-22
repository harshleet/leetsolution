class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        if(grid[0][0]==1){
            return -1;
        }
        pq.push({1,0,0});
        dist[0][0]=1;

        vector<int>dr={1,0,-1,0,-1,1,-1,1};
        vector<int>dc={0,1,0,-1,-1,1,1,-1};
        while(!pq.empty()){
            auto it=pq.top();
            int dis=get<0>(it);
            int r=get<1>(it);
            int c=get<2>(it);
            pq.pop();

            for(int i=0;i<8;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m &&  grid[nr][nc]==0 && dis+1<dist[nr][nc]){
                    dist[nr][nc]=dis+1;
                    pq.push({dis+1,nr,nc});
                }
            }

        }
        if(dist[n-1][m-1]==1e9){
            return -1;
        }
        return dist[n-1][m-1];
    }
};