class Solution {
public:
    void dfs(int node,vector<int>&vis,vector<int>&pvis,vector<vector<int>>&adj,int& maxi,int no){
        vis[node]=1;
        pvis[node]=no;

        for(auto it:adj[node]){
            if(vis[it]==0){
                dfs(it,vis,pvis,adj,maxi,no+1);
            }else if(pvis[it]!=0){
                maxi=max(maxi,no-pvis[it]+1);
            }
        }
        pvis[node]=0;
    }
    int longestCycle(vector<int>& edges) {
        //bfs se cycle detct hojaegi but length detct nhi hogi

        int n=edges.size();
        vector<int>pvis(n,0);
        vector<int>vis(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1)
               adj[i].push_back(edges[i]);
        }
        int maxi=-1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,pvis,adj,maxi,1);
            }
        }
        return maxi;
    }
};