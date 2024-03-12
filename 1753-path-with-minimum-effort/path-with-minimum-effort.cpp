class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;

        pq.push({0,0,0});
        dis[0][0]=1;
        vector<int>dr={1,-1,0,0};
        vector<int>dc={0,0,1,-1};
        while(!pq.empty()){
            int dist=get<0>(pq.top());
            int row=get<1>(pq.top());
            int col=get<2>(pq.top());
            pq.pop();
            if(row==n-1 && col==m-1){
                return dist;
            }
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                int maxi=max(dist,abs(heights[row][col]-heights[nrow][ncol]));
                if(dis[nrow][ncol]>maxi){
                    dis[nrow][ncol]=maxi;
                    pq.push({maxi,nrow,ncol});
                }
                }

            }
        }
        return -1;
    }
};