class Solution {
public:
    int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,long long>>>adj(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<long long int>dist(n,LLONG_MAX);
        vector<int>way(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        dist[0]=0;
        way[0]=1;

        while(!pq.empty()){
            long long di=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                if(dist[it.first]>it.second+di){
                    
                   dist[it.first]=it.second+di;
                    way[it.first]=way[node];
                    pq.push({dist[it.first],it.first});
                }else if(dist[it.first]==it.second+di){
                    cout<<it.first<<endl;
                    way[it.first]=(way[it.first]+way[node])%mod;
                }
            }

        }
         
        return way[n-1];
    }
};