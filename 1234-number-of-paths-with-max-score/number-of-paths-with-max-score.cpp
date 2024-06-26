class Solution {
public:
vector<int>dr={-1,0,-1};
vector<int>dc={0,-1,-1};
    int helper(int r,int c,vector<string>&board,vector<vector<int>>&dp,int n){
        if(r==0 && c==0){
            return 0;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int maxi=INT_MIN;
        for(int i=0;i<3;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nc>=0 && nr<n && nc<n && board[nr][nc]!='X'){
                maxi=max(maxi,helper(nr,nc,board,dp,n));
            }
        }
        int cell_val=0;
        if(r!=n-1 || c!=n-1){
            cell_val=(board[r][c]-'0');
            // cout<<cell_val<<endl;
        }
        return dp[r][c]=maxi+cell_val;
    }
    int mod=1e9+7;
    int helper2(int r,int c,int val,vector<string>&board,vector<vector<vector<int>>>&dp2,int n){
        if(r==0 && c==0){
            if(val==0){
                return 1;
            }
              return 0;
        }
        if(val<0){
            return 0;
        }
        if(dp2[r][c][val]!=-1){
            return dp2[r][c][val];
        }
         int cell_val=0;
        if(r!=n-1 || c!=n-1){
            cell_val=(board[r][c]-'0');
        }
        int cnt=0;
        for(int i=0;i<3;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nc>=0 && nr<n && nc<n && board[nr][nc]!='X'){
                cnt=(cnt+helper2(nr,nc,val-cell_val,board,dp2,n))%mod;
            }
        }
       
        return dp2[r][c][val]=cnt;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n=board.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
       
        int mx=helper(n-1,n-1,board,dp,n);
        if(mx<0){
            return {0,0};
        }
         vector<vector<vector<int>>>dp2(n,vector<vector<int>>(n,vector<int>(mx+1,-1)));
        int cp=helper2(n-1,n-1,mx,board,dp2,n);
        return {mx,cp};
    }
};