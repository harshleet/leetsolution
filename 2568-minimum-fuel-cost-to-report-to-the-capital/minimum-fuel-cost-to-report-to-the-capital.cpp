typedef long long  ll;
class Solution {
public:
   long long dist=0;
   pair<ll,ll> helper(int node,vector<int>&vis,int seats,vector<vector<int>>&adj,int dis){
      vis[node]=1;

      ll car=0,peo=1;
      for(auto it:adj[node]){
           if(!vis[it]){
                pair<ll,ll>p=helper(it,vis,seats,adj,dis+1);
                dist+=p.first;
                peo+=p.second;
          }
        }
        
        car=ceil(peo/(double)seats);
        // cout<<node<<" "<<vs<<" "<<dist<<endl;
        return {car,peo};
   }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size()+1;
        vector<vector<int>>adj(n);
        for(auto it:roads){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        vis[0]=1;
        int dis=0,vs=0;
        for(auto it:adj[0]){
            pair<ll,ll>p=helper(it,vis,seats,adj,1);
            dist+=p.first;
            vs+=p.second;
        }
        return dist;
    }
};