class Solution {
public:
   int dr[4]={1,-1,0,0};
   int dc[4]={0,0,-1,1};
    bool dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>&grid1,vector<vector<int>>& grid2,int n,int m){
       vis[row][col]=1;
       bool ans=true;
       if(grid1[row][col]==0 && grid2[row][col]==1){
           ans=false;
       }
       
       for(int i=0;i<4;i++){
           int nrow=row+dr[i];
           int ncol=col+dc[i];
           if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid2[nrow][ncol]==1 && !vis[nrow][ncol]){
               ans&=dfs(nrow,ncol,vis,grid1,grid2,n,m);
           }
       }
       return ans;
   }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size(),m=grid1[0].size();
         vector<vector<int>>vis(n,vector<int>(m,0));
         int maxi=0;
         for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(grid2[i][j]==1 && !vis[i][j]){
                     bool a=dfs(i,j,vis,grid1,grid2,n,m);
                     cout<<i<<" "<<j<<" "<<a<<endl;
                     if(a){
                         maxi++;
                     }
                 }
             }
         } 
         return maxi;
    }
};