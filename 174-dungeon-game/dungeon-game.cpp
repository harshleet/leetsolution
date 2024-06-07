class Solution {
public:
    // vector<int>dr={1,-1,0,0};
    // vector<int>dc={0,0,-1,1};
    int helper(int r,int c,vector<vector<int>>&dungeon,int n,int m,vector<vector<int>>&dp){
        if(r<0 || r>=n || c<0 || c>=m){
            return INT_MAX;
        }
        if(r==n-1 && c==m-1){
            if(dungeon[r][c]<=0){
                return 1-dungeon[r][c];
            }
            return 1;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        int mright=helper(r+1,c,dungeon,n,m,dp);
        int mleft=helper(r,c+1,dungeon,n,m,dp);
        
        int val=min(mright,mleft)-dungeon[r][c];
       
        if(val<=0){
            return dp[r][c]=1; 
        }
        return dp[r][c]=val;

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size();
        int m=dungeon[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(0,0,dungeon,n,m,dp);
    }
};