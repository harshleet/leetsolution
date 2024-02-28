class Solution {
public:
int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        
       vector<pair<long long,long long>>adj[n];
       for(int i=0;i<roads.size();i++){
           adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
           adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
       }
        vector<long long>dist(n,LONG_MAX);
        vector<long long>ways(n,0);
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
        dist[0]=0;
        ways[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            long long dis=pq.top().first;
            long long node=pq.top().second;
            pq.pop();
          
            for(auto it:adj[node]){
               if(dis+it.second<dist[it.first]){
                   dist[it.first]=dis+it.second;
                   ways[it.first]=(ways[node]);
                   pq.push({dist[it.first],it.first});
               }else if(dis+it.second==dist[it.first]){
                   ways[it.first]=(ways[it.first]+ways[node])%mod;
                   
               }
            }
           
        }
        return ways[n-1]%mod;;
    }

};