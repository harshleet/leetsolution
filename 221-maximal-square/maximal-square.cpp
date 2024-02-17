class Solution {
public:
    vector<int>drow={1,1,0};
    vector<int>dcol={1,0,1};
    int maxi=0;
    int dfs(int row,int col,vector<vector<int>>&dp,int n,int m,vector<vector<char>>& matrix){
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
       
        int mini=1e8;
        for(int i=0;i<3;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && ncol>=0 && nrow<n && ncol<m){
                mini=min(mini,dfs(nrow,ncol,dp,n,m,matrix));
            }else{
                 mini=min(mini,0);
            }
        }
         if(matrix[row][col]=='0'){
            return dp[row][col]=0;
        }
        maxi=max(maxi,mini+1);
        return dp[row][col]=mini+1;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        dfs(0,0,dp,n,m,matrix);
        if(maxi>=1e8){
            return 1;
        }
        return maxi*maxi;
    }
};