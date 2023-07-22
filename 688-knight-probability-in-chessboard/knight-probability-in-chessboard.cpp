class Solution {
public:
int drow[8]={1,-1,2,-2,1,-1,2,-2};
int dcol[8]={2,2,1,-1,-2,-2,-1,1};
   double dfs(int row,int col,int n,int k,vector<vector<vector<double>>>&dp){
        if(row<0 || row>=n||col<0 || col>=n){
             return 0.0;
        }
        if(k==0){
            return 1.0;
        }
        if(dp[row][col][k]!=-1){
            return dp[row][col][k];
        }
        double ans=0;
        for(int i=0;i<8;i++){
            int nrow=row+ drow[i];
            int ncol=col+ dcol[i];
            ans+= dfs(nrow,ncol,n,k-1,dp);
            
        }
        return dp[row][col][k]=ans;
    }

    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        double get=dfs(row,column,n,k,dp); 
        double tot=pow(8,k);
        return get/tot;
    }
};