class Solution {
public:
  void dfs(int node,int no,vector<int>&vis,vector<int>&pvis,vector<vector<int>>&adj,int &maxi){
    vis[node]=1;
    pvis[node]=no;
    // cout<<node<<endl;
         for(auto it:adj[node]){
                if(vis[it]==0){
                   dfs(it,no+1,vis,pvis,adj,maxi);
                }else if(pvis[it]!=0){
                    maxi=max(maxi,abs(pvis[node]-pvis[it]+1));
                }
       }
       pvis[node]=0;
  }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<vector<int>>adj(n);

        for(int i=0;i<edges.size();i++){
            if(edges[i]!=-1)
               adj[i].push_back(edges[i]);
        }
        vector<int>vis(n,0);
        vector<int>pvis(n,0);
        int maxi=-1;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,1,vis,pvis,adj,maxi);
            }
        }
        return maxi;
       
    }
};