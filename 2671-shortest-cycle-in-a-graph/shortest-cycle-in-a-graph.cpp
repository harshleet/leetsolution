class Solution {
public:
        int mini=INT_MAX;
       vector<int>lvl;
        void dfs(int node,int par,int l,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pvis){
                // vis[node]=1;
                // pvis[node]=1;
                lvl[node]=l;
                for(auto it:adj[node]){
                        if(lvl[it]>l+1){
                                dfs(it,node,l+1,adj,vis,pvis);
                        }else if(it!=par && lvl[it]<l){
                                 mini=min(mini,l-lvl[it]+1);
                        }
                }
                // pvis[node]=0;
        }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
            vector<vector<int>>adj(n);
            for(int i=0;i<edges.size();i++){
                    adj[edges[i][0]].push_back(edges[i][1]);
                    adj[edges[i][1]].push_back(edges[i][0]);
            }
           vector<int>vis(n,0);
           vector<int>pvis(n,0);
            lvl.resize(n,INT_MAX);
            for(int i=0;i<n;i++){
                    if(lvl[i]==INT_MAX){
                            dfs(i,-1,0,adj,vis,pvis);
                    }
            }
            if(mini==INT_MAX){
                    return -1;
            }
            return mini;
            
    }
};