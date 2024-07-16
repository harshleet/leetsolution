class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int>dist(n,1e9);
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;

        pq.push({0,0,src});
        dist[src]=0;
        while(!pq.empty()){
            int stop=get<0>(pq.top());
            int cost=get<1>(pq.top());
            int node= get<2>(pq.top());
            pq.pop();

            if(stop>k){
                continue;
            }

            for(auto it:adj[node]){
                if(it.second+cost<dist[it.first]){
                    dist[it.first]=it.second+cost;
                    pq.push({stop+1,dist[it.first],it.first});
                }
            }
        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};