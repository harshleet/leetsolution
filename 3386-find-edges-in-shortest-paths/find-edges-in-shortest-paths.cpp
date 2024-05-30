class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<long long int> dist(n, INT_MAX);
        vector<bool> ans(edges.size(), false);
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        priority_queue<pair<long long int, long long int>,
                       vector<pair<long long int, long long int>>,
                       greater<pair<long long int, long long int>>>
            pq;
        pq.push({0, 0});
        dist[0] = 0;
        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node]) {
                if (dist[it.first] > dis + it.second) {
                    dist[it.first] = dis + it.second;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        int mini=dist[n-1];
        if (dist[n - 1] == INT_MAX) {
            return ans;
        }
        vector<long long int> dist2(n, INT_MAX);
        priority_queue<pair<long long int, long long int>,
                       vector<pair<long long int, long long int>>,
                       greater<pair<long long int, long long int>>>
            pq2;
        pq2.push({0, n-1});
        dist2[n-1] = 0;
        while (!pq2.empty()) {
            int dis = pq2.top().first;
            int node = pq2.top().second;
            pq2.pop();
            for (auto it : adj[node]) {
                if (dist2[it.first] > dis + it.second) {
                    dist2[it.first] = dis + it.second;
                    pq2.push({dist2[it.first], it.first});
                }
            }
        }
        for(int i=0;i<dist2.size();i++){
            cout<<dist[i]<<" ";
            cout<<dist2[i]<<" ";
            cout<<endl;
        }
        for(int i=0;i<edges.size();i++){
            if((dist[edges[i][0]]+dist2[edges[i][1]]+edges[i][2]==mini)||(dist[edges[i][1]]+dist2[edges[i][0]]+edges[i][2]==mini)){
                ans[i]=true;
            }
        }
        return ans;
    }
};