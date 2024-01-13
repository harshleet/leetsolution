class Solution {
public:
     void dfs(int node,vector<int>&ds,vector<vector<int>>&ans,vector<vector<int>>&graph,vector<int>&vis){
         if(node==graph.size()-1){
             if(!ds.empty()){
                 ans.push_back(ds);
             }
             return;
         }
         for(auto it:graph[node]){
             int child=it;
             if(!vis[it]){
                 vis[it]=1;
                 ds.push_back(it);
                 dfs(it,ds,ans,graph,vis);
                 ds.pop_back();
                 vis[it]=0;
             }
         }
     }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>ds;
        vector<vector<int>>ans;
        vector<int>vis(n,0);
        vis[0]=1;
        ds.push_back(0);
        dfs(0,ds,ans,graph,vis);
        return ans;
    }
};