class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>adj(n);

        int j=0;
        for(auto it:edges){
            adj[it[0]].push_back({it[1],succProb[j]});
             adj[it[1]].push_back({it[0],succProb[j]});
            j++;
        }
        vector<double>dis(n,0.0);
        priority_queue<pair<double,int>>pq;

        pq.push({1.0,start_node});
        dis[start_node]=1.0;
        while(!pq.empty()){
            double prob=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                double val=prob*it.second;
                if(dis[it.first]<val){
                    dis[it.first]=val;
                    pq.push({val,it.first});
                }
            }

        }

        return dis[end_node];

    }
};