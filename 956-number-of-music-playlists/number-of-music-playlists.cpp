class Solution {
public:
     int mod=1e9+7;

     long long helper(vector<vector<int>>&dp,int n, int goal, int k){
        if (n == 0 && goal == 0) return 1;
        if (n == 0 || goal == 0) return 0;

         if(dp[n][goal]!=-1){
             return dp[n][goal];
         }
       long long ntake=helper(dp,n,goal-1,k)*max(n-k,0);
       long long take=helper(dp,n-1,goal-1,k)*(n);
        return dp[n][goal]=(take+ntake)%mod;
     }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>>dp(n+1,vector<int>(goal+1,-1));
        return helper(dp,n,goal,k);

    }
};