class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        
        pq.push({grid[0][0],0,0});
        dist[0][0]=grid[0][0];

        vector<int>dr={1,0};
        vector<int>dc={0,1};
        while(!pq.empty()){
            auto it=pq.top();
            int dis=get<0>(it);
            int r=get<1>(it);
            int c=get<2>(it);
            pq.pop();

            for(int i=0;i<2;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && dis+grid[nr][nc]<dist[nr][nc]){
                    dist[nr][nc]=dis+grid[nr][nc];
                    pq.push({dis+grid[nr][nc],nr,nc});
                }
            }

        }
        return dist[n-1][m-1];
    }
};