class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>>dis(n,vector<int>(m,1e9));
        priority_queue<tuple<int,int, int>, vector<tuple<int,int, int>>, greater<tuple<int,int, int>>> pq;
        if(grid[0][0]==1){
                pq.push({1,0,0});
                dis[0][0]=1;
        }else{
            pq.push({0,0,0});
            dis[0][0]=0;
        }
        int drow[]={1,-1,0,0};
        int dcol[]={0,0,1,-1};
        while(!pq.empty()){
            int dist=get<0>(pq.top());
            int row=get<1>(pq.top());
            int col=get<2>(pq.top());
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && dist+grid[nrow][ncol]<dis[nrow][ncol]){
                    dis[nrow][ncol]=dist+grid[nrow][ncol];
                    pq.push({dist+grid[nrow][ncol],nrow,ncol});
                }
            }
        }
         return dis[n-1][m-1];
        
    }
};