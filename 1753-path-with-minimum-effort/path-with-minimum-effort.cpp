class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<int>dr={1,-1,0,0};
        vector<int>dc={0,0,-1,1};

        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;

        int ans=INT_MAX;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        pq.push({0,0,0});
        dist[0][0]=0;
        while(!pq.empty()){
            int dis=get<0>(pq.top());
            int r=get<1>(pq.top());
            int c=get<2>(pq.top());
            pq.pop();

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int mini=max(dis,abs(heights[nr][nc]-heights[r][c]));
                     if(dist[nr][nc]>mini){
                        dist[nr][nc]=mini;
                        pq.push({mini,nr,nc});
                     }
                }
               
            }
            
        }
        return dist[n-1][m-1];
    }
};