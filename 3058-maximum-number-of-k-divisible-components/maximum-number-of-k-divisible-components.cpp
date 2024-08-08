class Solution {
public:
    long long  helper(int node,vector<vector<int>>&adj,vector<int>&values,vector<int>&vis){
        long long ans=0;
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
              ans+=helper(it,adj,values,vis);
            }
        }
        return ans+values[node];
    }

    long long  dfs(int node,vector<vector<int>>&adj,long long  tot,int k,vector<int>&values,int &val,vector<int>&vis){
        long long  sum=0;
        vis[node]=1;
        for(auto it:adj[node]){

           if(!vis[it]){ 
            long long  t=dfs(it,adj,tot,k,values,val,vis);
            sum+=t;
            if(t%k==0 && (tot-t)%k==0){
                val++;
            }}
        }
        return sum+values[node];

    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        
        vector<vector<int>>adj(n);
        
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        long long tot=helper(0,adj,values,vis);
         int val=1;
         vector<int>vis2(n,0);
        dfs(0,adj,tot,k,values,val,vis2);
        
        return val;
    }
};