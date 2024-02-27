class Solution {
public:
    bool dfs(int node,int colr,vector<vector<int>>& graph,vector<int>&vis,vector<int>&col){
        col[node]=colr;
        bool a=true;
        for(auto it:graph[node]){
            if(col[it]==-1){
              a&=dfs(it,abs(colr-1),graph,vis,col);
            }else if(col[it]==colr){
                a=false;
            }

        }
        return a;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>vis(n,0);
        vector<int>col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
               bool a=dfs(i,0,graph,vis,col);
               if(a==false)return false; 
            }
        }
       return true;
    }
};