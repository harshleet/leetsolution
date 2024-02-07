class Solution {
public:
int dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid,int n,int m,map<pair<int,int>,int>&mp,int id){
       vis[row][col]=1;
       mp[{row,col}]=id;
       int dr[]={1,-1,0,0};
       int dc[]={0,0,-1,1};
       int ans=1;
       for(int i=0;i<4;i++){
           int nrow=row+dr[i];
           int ncol=col+dc[i];
           if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
               ans+=dfs(nrow,ncol,vis,grid,n,m,mp,id);
           }
       }
       return ans;
   }
    int largestIsland(vector<vector<int>>& grid) {
         int n=grid.size(),m=grid[0].size();
         vector<vector<int>>vis(n,vector<int>(m,0));
         int maxi=0;
         int id=0;
         map<pair<int,int>,int>mp;
         map<int,int>size;
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(grid[i][j]==1 && !vis[i][j]){
                     int sz=dfs(i,j,vis,grid,n,m,mp,id);
                    maxi=max(maxi,sz);
                    size[id]=sz;
                    id++;
                 }
             }
         } 
       int dr[]={1,-1,0,0};
       int dc[]={0,0,-1,1};
          for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(grid[i][j]==0){
                     int v=0;
                     set<int>s;
                     for(int k=0;k<4;k++){
                        int nrow=i+dr[k];
                        int ncol=j+dc[k];
                        
                        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1){
                            s.insert(mp[{nrow,ncol}]);
                        }
                    }
                    for(auto it:s){
                        v+=size[it];
                    }
                    maxi=max(maxi,1+v);
                 }
             }
         } 
         return maxi;
    }
};