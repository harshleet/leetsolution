class Solution {
public:
    int maxi=-1;
    void dfs(int node,int par,vector<vector<int>>&adj,vector<int>&pvis,vector<int>&vis,int n){
        vis[node]=1;
        if(par!=-1){
            pvis[node]=1+pvis[par];
        }else{
            pvis[node]=1;
        }
        
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,node,adj,pvis,vis,n);
            }else if(vis[it]==1 && pvis[it]!=0){
               
                maxi=max(maxi,1+pvis[node]-pvis[it]);
            }
        }
        pvis[node]=0;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        vector<int>pvis(n,0);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1)
                adj[i].push_back(edges[i]);
        }
        for(int i=0;i<n;i++){
            dfs(i,-1,adj,pvis,vis,n);
        }
        return maxi;
    }
};