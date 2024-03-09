class Solution {
public:
    int helper(int r,int c,vector<vector<int>>&grid,vector<vector<int>>&dp,int n,int m,vector<vector<int>>&vis,int cnt){
        if(r<0 || c<0 ||r>=n || c>=m || grid[r][c]==-1){
            return 0;
        }
        if(vis[r][c]==1){
            return 0;
        }
        if(grid[r][c]==2){
            if(cnt==0){
                return 1;
            }
           return 0;
        }
        vis[r][c]=1;
        int le=helper(r,c-1,grid,dp,n,m,vis,cnt-1);
        int ri=helper(r,c+1,grid,dp,n,m,vis,cnt-1);
        int dow=helper(r+1,c,grid,dp,n,m,vis,cnt-1);
        int up=helper(r-1,c,grid,dp,n,m,vis,cnt-1);
        vis[r][c]=0;
        return le+ri+dow+up;

    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int str=0,stc=0,cnt=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    str=i;
                    stc=j;
                }
                if(grid[i][j]==0){
                    cnt++;
                }

            }
        }
        vector<vector<int>>vis(n,vector<int>(m,0));
        return helper(str,stc,grid,dp,n,m,vis,cnt);
    }
};