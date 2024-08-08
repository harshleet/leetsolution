class Solution {
public:
    vector<int> dfs(int node,vector<vector<int>>&adj,string& labels,vector<int>&ans,vector<int>&vis){
        vis[node]=1;
        char key=labels[node];

        vector<int>my(26,0);
        my[key-'a']++;
        int cnt=0;
        for(auto it:adj[node]){
            if(!vis[it]){vector<int>temp=dfs(it,adj,labels,ans,vis);
            // cnt+=temp[key-'a'];
            for(int i=0;i<26;i++){
                my[i]+=temp[i];
            }}
        }
        ans[node]=my[key-'a'];
        return my;

    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>ans(n,0);
        vector<int>vis(n,0);
        dfs(0,adj,labels,ans,vis);
        return ans;
    }
};