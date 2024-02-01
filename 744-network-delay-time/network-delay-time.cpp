class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }

        vector<int>dis(n+1,1e9);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,k});
        dis[k]=0;

        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                if(dist+it.second<dis[it.first]){
                    dis[it.first]=dist+it.second;
                    pq.push({dist+it.second,it.first});
                }
            }
        }
        int maxi=0;
        for(int i=1;i<=n;i++){
             if(dis[i]==1e9){
                  return -1;
            }
              maxi=max(maxi,dis[i]);
        }
        
        return maxi;
    }
};