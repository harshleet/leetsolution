class Solution {
public:
    int helper(int row,int col,vector<vector<int>>&dp,vector<vector<int>>& matrix,int& n,int& m){
        if(row<0 || row>=n || col>=m || col<0){
            return 1e8;
        }
        if(row==n-1){
            return matrix[row][col];
        }
        
       
        if(dp[row][col]!=1e9 ){
            return dp[row][col];
        }

        int drow[]={1,1,1};
        int dcol[]={-1,0,1};
        int mini=1e8;
        for(int i=0;i<3;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            mini=min(mini,helper(nrow,ncol,dp,matrix,n,m));
        }
        return dp[row][col]=matrix[row][col]+mini;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1e9));
        int mini=1e8;
        for(int i=0;i<m;i++){
             mini=min(mini,helper(0,i,dp,matrix,n,m));
        }
        return mini;
    }
};