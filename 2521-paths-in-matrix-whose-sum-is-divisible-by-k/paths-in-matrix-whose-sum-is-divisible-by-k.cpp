class Solution {
public:
int mod=1e9+7;
vector<int>dr={1,0};
vector<int>dc={0,1};
    int helper(int r,int c,int re,int k,vector<vector<vector<int>>>&dp,int n,int m,vector<vector<int>>& grid){
            if(r==n-1 && c==m-1){
                re=(re+grid[r][c])%k;
                if(re==0){
                    return 1;
                }
                return 0;
            }
            if(dp[r][c][re]!=-1){
                return dp[r][c][re];
            }
             int cn=0;
            for(int i=0;i<2;i++){
                 int nr=r+dr[i];
                 int nc=c+dc[i];
                 if(nr>=0 && nc>=0 && nr<n && nc<m ){
                    cn=(cn+helper(nr,nc,(re+grid[r][c])%k,k,dp,n,m,grid))%mod;
                 }
            }
            return dp[r][c][re]=cn;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        return helper(0,0,0,k,dp,n,m,grid);
    }
};