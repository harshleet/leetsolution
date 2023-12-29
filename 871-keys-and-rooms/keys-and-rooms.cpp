class Solution {
public:
  void dfs(int ind,vector<int>adj[],vector<int>&vis){
      vis[ind]=1;

      for(auto it:adj[ind]){
          if(!vis[it]){
              dfs(it,adj,vis);
          }
      }
  }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
      vector<int>adj[rooms.size()];
      for(int i=0;i<rooms.size();i++){
          for(int j=0;j<rooms[i].size();j++){
              adj[i].push_back(rooms[i][j]);
          }
      }
      vector<int>vis(rooms.size(),0);
        dfs(0,adj,vis);  
        for(int i=0;i<rooms.size();i++){
            if(vis[i]==0){
                return false;
            }
        }
        return true;
    }
};