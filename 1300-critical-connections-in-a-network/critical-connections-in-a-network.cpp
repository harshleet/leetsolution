class Solution {
public:
    void dfs(int node,int par,int timer, vector<vector<int>>&ans,vector<int>adj[],vector<int>&vis, vector<int>&intime,vector<int>&low){
        vis[node]=1;
        intime[node]=timer;
        low[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==par){
                continue;
            }
            if(vis[it]==0){
                dfs(it,node,timer,ans,adj,vis,intime,low);
                low[node]=min(low[node],low[it]);
                if(low[it]>intime[node]){
                    ans.push_back({it,node});
                }
            }else{
                  low[node]=min(low[node],low[it]);
            }

        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>adj[n];
        vector<int>vis(n,0);
        int step=1;
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int timer=1;
        vector<int>intime(n);
        vector<int>low(n);
        vector<vector<int>>ans;
        dfs(0,-1,timer,ans,adj,vis,intime,low);
        return ans;
    }
};