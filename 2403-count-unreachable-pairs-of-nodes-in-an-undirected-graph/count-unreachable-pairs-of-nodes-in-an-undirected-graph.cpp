class Solution {
public:
   long long dfs(int node,vector<int>&vis,vector<vector<int>>&adj){
    vis[node]=1;
    long long cnt=0;
    for(auto it:adj[node]){
        if(!vis[it]){
            cnt+=dfs(it,vis,adj);
        }
    }
    return 1+cnt;
   }
    long long countPairs(int n, vector<vector<int>>& edges) {
        if(edges.size()==0){
            long long a=n;
            a*=(n-1);
            return a/2;
        }
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        long long ans=0;
        int is=0;
        vector<long long int>sz;
        for(int i=0;i<n;i++){
            if(!vis[i]){
               long long int vl=dfs(i,vis,adj);
               sz.push_back(vl);
            }
        }
        for(int i=0;i<sz.size();i++){
            for(int j=i+1;j<sz.size();j++){
                ans+=sz[i]*sz[j];
            }
        }
        return ans;
    }
};