// class Solution {
// public:
//  int dfs(int node,vector<int>&vis,int n,vector<int>adj[],int lvl){
     
     
//      vis[node]=1;
//      int c=0;
//      for(auto it:adj[node]){
//         if(!vis[it]){
//             c+=lvl+dfs(it,vis,n,adj,lvl+1);
//         }
//      }  
//      return dp[node][lvl]=c;
//  }

//     vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
//         vector<int>ans(n);
//         vector<int>adj[n];
//         for(int i=0;i<edges.size();i++){
//             adj[edges[i][0]].push_back(edges[i][1]);
//             adj[edges[i][1]].push_back(edges[i][0]);
//         }
//         // vector<vector<int>>dp(n,vector<int>(10000,-1));
//         for(int i=0;i<n;i++){
//             // map<int,map<int,int>>m;
//             int c=dfs(i,vis,n,adj,1);
//             ans[i]=c;
//         }
//         return ans;
//     }
// };


class Solution {
public:
     void dfs(int node,vector<int>&ans,vector<int>&nchild,vector<int>&vis,vector<int>adj[]){
           vis[node]=1;
           for(auto it:adj[node]){
              if(!vis[it]){
                   dfs(it,ans,nchild,vis,adj);
                   nchild[node]+=nchild[it];
                   ans[node]+=ans[it]+nchild[it];
              }
           }
     }  void dfs2(int node,vector<int>&ans,vector<int>&nchild,vector<int>&vis1,vector<int>adj[]){
           vis1[node]=1;
           for(auto it:adj[node]){
              if(!vis1[it]){
                   ans[it]=ans[node]-nchild[it]+(ans.size()-nchild[it]);
                    dfs2(it,ans,nchild,vis1,adj);
              }
           }
        
     }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>ans(n,0);
        vector<int>nchild(n,1);
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n,0);
        dfs(0,ans,nchild,vis,adj);
         vector<int>vis1(n,0);
         dfs2(0,ans,nchild,vis1,adj);
        return ans;
    }
};