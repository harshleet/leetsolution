class Solution {
public:
   vector<int>dr={1,0};
   vector<int>dc={0,1};
   int mod=1e9+7;
   int helper(int r,int c,int rem,int n,int m,int k,vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
    if(r==n-1 && c==m-1){
        if(rem==0){
            return 1;
        }
        return 0;
    }
    if(dp[r][c][rem]!=-1){
        return dp[r][c][rem];
    }
    int ans=0;
    for(int i=0;i<2;i++){
        int nr=r+dr[i];
        int nc=c+dc[i];

        if(nr>=0 && nc>=0 && nr<n && nc<m){
            ans=(ans+helper(nr,nc,(rem+(grid[nr][nc])%k)%k,n,m,k,grid,dp))%mod;
        }
    }
    return dp[r][c][rem]=ans;
   }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k,-1)));
        return helper(0,0,grid[0][0]%k,n,m,k,grid,dp);
    }
};