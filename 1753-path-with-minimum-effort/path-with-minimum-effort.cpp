class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.push({0,0,0});
        dist[0][0]=0;
        vector<int>drow={0,0,-1,1};
        vector<int>dcol={-1,1,0,0};
       int maxi=0;
        while(!pq.empty()){
            int h=get<0>(pq.top());
            int row=get<1>(pq.top());
            int col=get<2>(pq.top());
            pq.pop();
            if(row==n-1 && col==m-1){
                return h;
            }
            for(int i=0;i<4;i++){
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                    int maxd=max(h,abs(heights[nrow][ncol]-heights[row][col]));
                    if(maxd<dist[nrow][ncol]){
                        dist[nrow][ncol]=maxd;
                        pq.push({dist[nrow][ncol],nrow,ncol});
                    }
                }
            }

        }
        return 0;
    }
};