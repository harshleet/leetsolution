class Solution {
public:
int maxi=-1;
    void dfs(int node,vector<int>adj[],vector<int>&vis,vector<int>&len,int lvl,vector<int>&pvis){
         vis[node]=1;
               len[node]=lvl;
               pvis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
               
               dfs(it,adj,vis,len,lvl+1,pvis);
                
            }else if(pvis[it]){
                    maxi=max(maxi,lvl-len[it]);
             }
        }
       pvis[node]=0;
      
    }
    int longestCycle(vector<int>& edges) {
        
        int n=edges.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            if(edges[i]!=-1)
               adj[i].push_back(edges[i]);
        }
        vector<int>vis(n,0);
        vector<int>len(n,0);
        vector<int>pvis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,len,0,pvis);
            }
        }
        if(maxi==-1){
            return -1;
        }
        return maxi+1;
    }
};