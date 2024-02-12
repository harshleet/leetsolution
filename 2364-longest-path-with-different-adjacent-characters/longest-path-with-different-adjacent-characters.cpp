class Solution {
public:
int maxii=0;
  void helper(vector<int>&par,vector<int>adj[]){
      for(int i=0;i<par.size();i++){
        if(par[i]!=-1){
            adj[par[i]].push_back(i);
        }
      }
  }
  int dfs(int node,vector<int>adj[],string& s){
       vector<int>val;
       for(auto it:adj[node]){
           int v=dfs(it,adj,s);
           if(s[node]!=s[it]){
               val.push_back(v);
           }
       }
       sort(val.begin(),val.end());
       int max1=0,max2=0;
       if(val.size()>1){
           max1=val[val.size()-2];
       }if(val.size()>0){
           max2=val[val.size()-1];
       }
       int max_got=1+max2;
       maxii=max(maxii,1+max1+max2);
       maxii=max(maxii,1+max2);
       return max_got;
  }
    int longestPath(vector<int>& parent, string s) {
        if(parent.size()==0){
            return 0;
        }
        int n=parent.size();
        vector<int>adj[n];
        //make it a graph
        helper(parent,adj);
        int val=dfs(0,adj,s);
        return maxii=max(val,maxii);
        
    }
};