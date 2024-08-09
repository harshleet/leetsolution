class Solution {
public:
vector<int>dr={-2,-2,2,2,-1,-1,1,1};
vector<int>dc={-1,1,-1,1,-2,2,-2,2};
    double helper(int r,int c,int n,int k,vector<vector<vector<double>>>&dp){
        if(r<0 || c<0 || r>=n || c>=n){
            return 0.0;
        }
        if(k==0){
            return 1.0;
        }
        if(dp[r][c][k]!=-1){
            return dp[r][c][k];
        }
        double ans=0;
        for(int i=0;i<8;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            ans+=helper(nr,nc,n,k-1,dp);
        }
        return dp[r][c][k]=ans;

    }
    double knightProbability(int n, int k, int row, int column) {
         vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        double in=helper(row,column,n,k,dp);
        // cout<<in<<" ";
       
        return in/(double)(pow(8,k));
    }
};