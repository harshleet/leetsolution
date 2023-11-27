class Solution {
public:
int mod=1e9+7;
    int helper(int row,int col,int moves, vector<vector<int>>&v,vector<vector<vector<int>>>&dp){
        if(moves==0){
            return 1;
        }
        if(dp[row][col][moves]!=-1){
            return dp[row][col][moves];
        }
        int dr[]={1,-1,1,-1,2,-2,2,-2};
        int dc[]={2,2,-2,-2,1,1,-1,-1};
        int ans=0;
        for(int i=0;i<8;i++){
            int nrow=row+dr[i];
            int ncol=col+dc[i];

            if(nrow>=0 && ncol>=0 && ncol<v[0].size() && nrow<v.size() && v[nrow][ncol]!=-1){ 
                ans=(ans+helper(nrow,ncol,moves-1,v,dp))%mod;
            }
        }
        return dp[row][col][moves]= ans;

    }
    int knightDialer(int n) {
        
        //simple approach go through the backtracing
        vector<vector<int>>v={{1,2,3},{4,5,6},{7,8,9},{-1,0,-1}};
        vector<vector<vector<int>>>dp(v.size(),vector<vector<int>>(v[0].size(),vector<int>(n+1,-1)));
         int ans=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(v[i][j]!=-1){
                    ans=(ans+helper(i,j,n-1,v,dp))%mod;
                } 
            }
        }
        return ans;
    }
};