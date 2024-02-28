class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,int>>adj[n];
        for(int i=0;i<points.size();i++){
          for(int j=i+1;j<points.size();j++){
              adj[i].push_back({j,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])});
              adj[j].push_back({i,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])});
          }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});

        vector<int>vis(n,0);
       
        int ans=0;
        while(!pq.empty()){
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            if(vis[node]==1){
                continue;
            }
             vis[node]=1;
            ans+=wt;
            for(auto it:adj[node]){
                if(!vis[it.first]){
                    
                    pq.push({it.second,it.first});
                }
            }
        }
        return ans;

    }
};