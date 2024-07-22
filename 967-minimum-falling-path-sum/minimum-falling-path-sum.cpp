class Solution {
public:
    vector<int>dc={-1,0,1};
    int helper(int r,int c,int n,int m,vector<vector<int>>&dp,vector<vector<int>>&matrix){
        if(r==n-1){
            return matrix[r][c]; 
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int mini=INT_MAX;
        for(int i=0;i<3;i++){
            int nc=c+dc[i];
            if(nc>=0 && nc<m){
                mini=min(mini,helper(r+1,nc,n,m,dp,matrix));
            }
        }
        return dp[r][c]=mini+matrix[r][c];
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int r=1;r<n;r++){
            for(int c=0;c<m;c++){
                int mini=INT_MAX;
                if(c>0){
                    mini=min(mini,dp[r-1][c-1]);
                }
                mini=min(mini,dp[r-1][c]);
                if(c<m-1){
                    mini=min(mini,dp[r-1][c+1]);
                }
                dp[r][c]=mini+matrix[r][c];
            }
        }
        int mini=INT_MAX;
        for(int i=0;i<m;i++){
            mini=min(mini,dp[n-1][i]);
        }
        return mini;
        
    }
};