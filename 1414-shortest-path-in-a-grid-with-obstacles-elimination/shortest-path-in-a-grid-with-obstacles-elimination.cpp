class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<int>dr={1,-1,0,0};
        vector<int>dc={0,0,1,-1};


        vector<vector<vector<int>>>dis(n,vector<vector<int>>(m,vector<int>(k+1,1e8)));
        queue<array<int,4>>pq;
        

        if(grid[0][0]==1 && k>0){
            dis[0][0][1]=0;
            pq.push({0,1,0,0});
        }else if(grid[0][0]==1){
            return -1;
        }else{
            dis[0][0][0]=0;
            pq.push({0,0,0,0});
        }

        while(!pq.empty()){
            int dist=pq.front()[0];
            int ob=pq.front()[1];
            int r=pq.front()[2];
            int c=pq.front()[3];
            pq.pop();

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    if(grid[nr][nc]==1 && ob<k && dis[nr][nc][ob+1]>dist+1){
                        dis[nr][nc][ob+1]=dist+1;
                        pq.push({dis[nr][nc][ob+1],ob+1,nr,nc});
                    }else if(grid[nr][nc]==0 && dis[nr][nc][ob]>dist+1){
                        dis[nr][nc][ob]=dist+1;
                        pq.push({dis[nr][nc][ob],ob,nr,nc});
                    }
                }
            }
        }
        int mini=1e8;
        for(int i=0;i<=k;i++){
            mini=min(mini,dis[n-1][m-1][i]);
        }


        if(mini==1e8){
            return -1;
        }

        return mini;
        
    }
};