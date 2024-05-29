class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));

        dist[0][0]=0;
        pq.push({0,0,0});
        vector<int>dr={1,-1,0,0};
        vector<int>dc={0,0,-1,1};
        while(!pq.empty()){
            int maxE=get<0>(pq.top());
            int r=get<1>(pq.top());
            int c=get<2>(pq.top());
            pq.pop();
       
           if(r==n-1 && c==m-1){
            return maxE;
           }
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int maxi=max(maxE,abs(heights[nr][nc]-heights[r][c]));
                   
                    if(dist[nr][nc]>maxi){
                        dist[nr][nc]=maxi;
                        pq.push({maxi,nr,nc});
                    }
                }
            }
        }
        return 0;

    }
};