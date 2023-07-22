class Solution {
public:
int drow[4]={1,-1,0,0};
int dcol[4]={0,0,1,-1};
int mod=(1e9+7);
   long long int dfs(int row,int col,int m,int n,int k,vector<vector<vector<long long int>>>&dp){
        if(row<0 || row>=m||col<0 || col>=n){
             return 1;
        }
        if(k==0){
            return 0;
        }
        if(dp[row][col][k]!=-1){
            return dp[row][col][k];
        }
       long long int ans=0;
        for(int i=0;i<4;i++){
            int nrow=row+ drow[i];
            int ncol=col+ dcol[i];
            ans+= dfs(nrow,ncol,m,n,k-1,dp)%mod;
            
        }
        return dp[row][col][k]=ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
         vector<vector<vector<long long int>>>dp(m,vector<vector<long long int>>(n,vector<long long int>(maxMove+1,-1)));
       long long  int a=dfs(startRow,startColumn,m,n,maxMove,dp); 
         
        return a%mod;
    }
};