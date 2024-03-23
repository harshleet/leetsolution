class Solution {
public:
        vector<int>dr={1,0};
        vector<int>dc={0,1};
        bool helper(int r,int c,vector<vector<int>>&grid,int n,int m){
                grid[r][c]=0;
                if(r==n-1 && c==m-1){
                        return true; 
                }
                bool cnt=false;
                for(int i=0;i<2;i++){
                        int nrow=r+dr[i];
                        int ncol=c+dc[i];
                        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && grid[nrow][ncol]==1){
                                cnt=cnt||helper(nrow,ncol,grid,n,m);
                        }
                }
               
                return  cnt;
        }

    bool isPossibleToCutPath(vector<vector<int>>& grid) {
            int n=grid.size();
            int m=grid[0].size();
           
        bool dfs1=helper(0,0,grid,n,m);
           if(dfs1==false){
                   return true;
           }
            grid[0][0]=1;
            grid[n-1][m-1]=1;
            bool dfs2=helper(0,0,grid,n,m);
            if(dfs2==false){
                   return true;
           }
         
            return false;
    }
};