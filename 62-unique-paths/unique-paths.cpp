class Solution {
public:
vector<int>dr={1,0};
vector<int>dc={0,1};
    int helper(int r,int c,int m,int n,vector<vector<int>>&dp){
        if(r==m-1 && c==n-1){
            return 1;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int ans=0;
        for(int i=0;i<2;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(r>=0 && nc>=0 && nr<m && nc<n){
                  ans+=helper(nr,nc,m,n,dp); 
            }
        }
        return dp[r][c]=ans;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(0,0,m,n,dp);
    }
};