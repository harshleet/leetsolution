class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
         vector<pair<int,int>>adj[n+1];
          for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        queue<pair<int,int>>q;
        q.push({k,0});
        if(adj[k].size()==0){
            return -1;
        }
        while(!q.empty()){
            int node=q.front().first;
            int dis=q.front().second;
            q.pop();

            for(auto it:adj[node]){
                if(dis+it.second<dist[it.first]){
                    dist[it.first]=dis+it.second;
                    q.push({it.first,dis+it.second});
                }
            }
        }
        int mini=0;
         for(int i=1;i<=n;i++){
             if(dist[i]==1e9 ){
                 return -1;
             }
             mini=max(mini,dist[i]);
         }
         return mini;
    }
};