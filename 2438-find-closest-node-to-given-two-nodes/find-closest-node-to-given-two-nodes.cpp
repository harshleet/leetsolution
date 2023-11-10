class Solution {
public:
    void bfs(int node, vector<int>& dis, vector<int> adj[]) {
        queue<int> q;
        vector<int>vis(dis.size(),0);
        q.push(node);
        dis[node] = 0;
        vis[node]=1;
        while (!q.empty()) {
            int n = q.front();
            q.pop();
            for (auto it : adj[n]) {
                if (!vis[it] && dis[n] + 1 < dis[it]) {
                    dis[it] = dis[n] + 1;
                    vis[it]=1;
                    q.push(it); 
                }
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++) {
            if(edges[i]!=-1)
              adj[i].push_back(edges[i]);
        }
        vector<int> dis(n, 1e8);
        vector<int> dis2(n, 1e8);
        bfs(node1, dis, adj);
        bfs(node2, dis2, adj);
        int mini = INT_MAX;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            if (dis[i] == 1e8 || dis2[i] == 1e8) {
                continue;
            }
            int b = max(dis[i],dis2[i]);
            if (b < mini) {
                mini = b;
                ans = i;
            }
        }
        return ans;
    }
};