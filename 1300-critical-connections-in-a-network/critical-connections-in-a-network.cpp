class Solution {
public:
    vector<vector<int>>ans;
    int timer=0;
    void helper(int node,int parent,vector<vector<pair<int,int>>>&adj,vector<int>&disc,vector<int>&low,int n,vector<int>&vis,  vector<vector<int>>& connections){
        vis[node]=1;
        disc[node]=timer;
        low[node]=timer;
        timer++;


        for(auto it:adj[node]){
            if(!vis[it.first]){
                // not visited and definetely not a parent
                helper(it.first,node,adj,disc,low,n,vis,connections);
                // update the low with something if child had been reached
                low[node]=min(low[node],low[it.first]);

                // now we check disc
                if(low[it.first]>disc[node]){
                    ans.push_back(connections[it.second]);
                }

            }else if(it.first==parent){
                //if parent do nothing
                continue;
            }else{
                //visted and not a parent
                low[node]=min(low[node],low[it.first]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // bridges question
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back({connections[i][1],i});
            adj[connections[i][1]].push_back({connections[i][0],i});
        }
        vector<int>disc(n,-1);
        vector<int>low(n);
        vector<int>vis(n);
        helper(0,-1,adj,disc,low,n,vis,connections);
        return ans;
    }
};