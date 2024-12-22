class Solution {
public:
    long long int  helper(int node,map<int,int>&mp,vector<int>&vis,vector<vector<int>>&adj,vector<int>& values,int &ans,int k){
        vis[node]=1;
        long long int sum=values[node];
        for(auto it:adj[node]){
            if(!vis[it]){
                sum+=helper(it,mp,vis,adj,values,ans,k);
            }
        }
        if(sum%k==0){
            ans++;
            return 0;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>adj(n);
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n);
        map<int,int>mp;
        int ans=0;

        long long int  val=helper(0,mp,vis,adj,values,ans,k);
        if(val%k==0){
            ans++;
        }
        return ans-1;
    }
};