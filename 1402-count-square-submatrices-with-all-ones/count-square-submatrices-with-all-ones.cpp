class Solution {
public:
int maxi=0;
    int helper(int r,int c,vector<vector<int>>&dp,vector<vector<int>>&matrix,int n,int m){
        if(r<0 ||c<0 || r>=n || c>=m){
            return 0;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        if(matrix[r][c]==0){
            return dp[r][c]=0;
        }
        int vl=1+min({helper(r+1,c,dp,matrix,n,m),helper(r,c+1,dp,matrix,n,m),helper(r+1,c+1,dp,matrix,n,m)});
        return dp[r][c]=vl;

    }
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            dp[i][0]=matrix[i][0];
        }
        for(int i=0;i<m;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]==0){
                    dp[i][j]=0;
                }else{
                    dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
                
            }
        }
    
    int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=dp[i][j];
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return sum;
    }
};