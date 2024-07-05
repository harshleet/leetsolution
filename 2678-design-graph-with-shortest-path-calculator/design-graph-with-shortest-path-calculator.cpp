class Graph {
public:
   vector<vector<pair<int,int>>>adj;
   int sz;
    int calc(int node1,int node2){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(sz,INT_MAX);
        pq.push({0,node1});
        dist[node1]=0;
        while(!pq.empty()){
            auto itr=pq.top();
            pq.pop();

            for(auto it:adj[itr.second]){
                if(itr.first+it.second<dist[it.first]){
                    dist[it.first]=itr.first+it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        if(dist[node2]==INT_MAX){
            return -1;
        }
        return dist[node2];
    }
    Graph(int n, vector<vector<int>>& edges) {
        adj.resize(n);
       sz=n;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        if(node1==node2){
            return 0;
        }
        return calc(node1,node2);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */