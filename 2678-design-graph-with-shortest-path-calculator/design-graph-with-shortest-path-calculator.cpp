class Graph {
public:
    vector<vector<pair<int,int>>>adj;
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int>dis(adj.size(),INT_MAX);
        priority_queue<pair<int,int>>pq;
        pq.push({0,node1});
        dis[node1]=0;

        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto it:adj[node]){
                if(dist+it.second<dis[it.first]){
                    dis[it.first]=dist+it.second;
                    pq.push({dist+it.second,it.first});
                }
            }
        }
        if(dis[node2]==INT_MAX){
            return -1;
        }
        return dis[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */