class Solution {
public:
    vector<int> bfs(int node,int n,  vector<int> adj[]) {
        vector<int>dis(n, 1e8);
        queue<int> q;
        vector<int>vis(n,0);
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
        return dis;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> adj[n];
        for (int i = 0; i < edges.size(); i++) {
            if(edges[i]!=-1)
              adj[i].push_back(edges[i]);
        }
    
        vector<int> dis= bfs(node1,n,adj);
        vector<int> dis2=bfs(node2,n, adj);
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