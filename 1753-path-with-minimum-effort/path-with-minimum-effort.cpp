class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size(),m=heights[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        pq.push({0,0,0});
        dis[0][0]=0;
        vector<int>dr={1,-1,0,0};
        vector<int>dc={0,0,-1,1};
        while(!pq.empty()){
            int diff=pq.top()[0];
            int r=pq.top()[1];
            int c=pq.top()[2];

            pq.pop();

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                
                if(nr>=0 && nc>=0 && nr<n && nc<m){
                    int maxi=max(diff,abs(heights[nr][nc]-heights[r][c]));
                    if(maxi<dis[nr][nc]){
                        dis[nr][nc]=maxi;
                        pq.push({dis[nr][nc],nr,nc});
                    }
                }
            }

        }
        return dis[n-1][m-1];
    }
};