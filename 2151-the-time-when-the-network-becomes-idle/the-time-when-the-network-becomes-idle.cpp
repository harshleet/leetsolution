class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        // try to find distance of each node from the 0
        int n = patience.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<pair<int, int>> q;
        vector<int> dist(n, INT_MAX);
        q.push({0, 0});
        dist[0] = 0;

        while (!q.empty()) {
            int node = q.front().second;
            int dis = q.front().first;
            q.pop();

            for (auto it : adj[node]) {
                if (dist[it] > 1 + dis) {
                    dist[it] = 1 + dis;
                    q.push({1 + dis, it});
                }
            }
        }
        // now try to find the time hen network becomes idle
        // check in that ouble of time how many packets will be releaesed nd ho
        // much last packet will take the ttime
        int maxi = 0;
        for (int i = 1; i < n; i++) {
            dist[i] *= 2;
            int no = (dist[i] - 1) / patience[i];
            if (no == 0) {
                maxi = max(maxi, dist[i] + 1);
            } else {
                maxi =
                    max(maxi, 1 + dist[i] +
                                  ((dist[i] - 1) / patience[i]) * patience[i]);
            }
        }
        return maxi;
    }
};