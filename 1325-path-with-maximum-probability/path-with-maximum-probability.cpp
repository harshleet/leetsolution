class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<pair<int, double>> adj[n];
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i] });
            adj[edges[i][1]].push_back({ edges[i][0], succProb[i] });  
        }
        priority_queue<pair<double,int>>pq;
        vector<double>dis(n,0.0);
        pq.push({1.0,start_node});
        dis[start_node]=1.0;

        while(!pq.empty()){
            double dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
 
            for(auto it:adj[node]){
                if(dist*it.second>dis[it.first]){
                    dis[it.first]=dist*it.second;
                    pq.push({dist*it.second,it.first});
                }
            }
        }
        return dis[end_node];

    }
};