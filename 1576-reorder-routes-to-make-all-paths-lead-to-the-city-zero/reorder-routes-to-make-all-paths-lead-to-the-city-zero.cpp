class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj,int& cnt,map<pair<int,int>,int>&m){
        vis[node]=1;
        // cout<<node<<endl;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(m.find({it,node})==m.end()){
                    // cout
                    cnt++;
                }
                dfs(it,vis,adj,cnt,m);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        map<pair<int,int>,int>m;
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            m[{it[0],it[1]}]++;
        }
        int cnt=0;
        dfs(0,vis,adj,cnt,m);
        return cnt;
    }
};