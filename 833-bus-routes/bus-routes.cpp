class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        map<int,vector<int>>adj;
        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                adj[routes[i][j]].push_back(i);
            }
        }

        queue<pair<int, int>> q;
        map<int, bool> m;
        map<int, bool> vis;
        q.push({source, 0});
        vis[source] = true;

        while (!q.empty()) {
            int stop = q.front().first;
            int lev = q.front().second;
            q.pop();

            if (stop == target) {
                               return lev;
                            }

            for (auto itr : adj[stop]) {
                if (m[itr] == false) {
                    m[itr] = true;
                    for (auto it : routes[itr]) {
                        if (vis[it] == false) {
                            
                            vis[it] = true;
                            q.push({it, lev + 1});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
