class Solution {
public:
vector<int>dc1={-1,1,0,-1,1,0,-1,1,0};
vector<int>dc2={-1,-1,-1,0,0,0,1,1,1};
    int helper(int r,int c1,int c2,vector<vector<int>>&grid,vector<vector<vector<int>>>&dp,int n,int m){
        if(r==n-1){
            if(c1==c2){
                return grid[r][c1];
            }
            return grid[r][c1]+grid[r][c2];
        }
        if(dp[r][c1][c2]!=-1){
            return dp[r][c1][c2];
        }
        int sum=0;
        if(c1==c2){
          sum=grid[r][c1];
        }else{
            sum=grid[r][c1]+grid[r][c2];
        }
         int maxi=0;
        for(int i=0;i<9;i++){
            int nc1=c1+dc1[i];
            int nc2=c2+dc2[i];
            if(nc1>=0 && nc2>=0 && nc1<m && nc2<m ){
                maxi=max(maxi,helper(r+1,nc1,nc2,grid,dp,n,m));
            }
        }
        return dp[r][c1][c2]=maxi+sum;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return helper(0,0,m-1,grid,dp,n,m);
    }
};