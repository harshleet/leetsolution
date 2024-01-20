class Solution {
public:
 int maxi=0;
    int helper(int row,int col,vector<vector<int>>&dp,vector<vector<char>>& matrix){
        if(row>=matrix.size()|| col>=matrix[0].size() ){
            return 0;
        }
        
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int drow[]={0,1,1};
        int dcol[]={1,0,1};
        int mini=1e8;
        for(int i=0;i<3;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            mini=min(mini,helper(nrow,ncol,dp,matrix));
        }
          if(matrix[row][col]=='0'){
                return dp[row][col]=0;
        }
        
        maxi=max(maxi,mini+1);
        return dp[row][col]=mini+1;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));       
        helper(0,0,dp,matrix);
        return maxi*maxi;
    }
};