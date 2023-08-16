class Solution {
public:
    int helper(int n, vector<vector<int>>& dp, int len, int op, int clen) {
        if (len> n) {
            return 1e8;
        }
        if(len==n){
            return 0;
        }
        
        if (dp[len][clen] != -1) {
            return dp[len][clen];
        }
        
        int copy = 1e8, paste = 1e8;
        if (op!=1) {
            copy =  1+ helper(n, dp, len, 1, len);
        }
        
        if (clen != 0) {
            paste = 1 + helper(n, dp, len + clen, 2, clen);
        }
        
        return dp[len][clen] = min(paste, copy);
    }
    
    int minSteps(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        if (n == 1) {
            return 0;
        }
        return helper(n, dp, 1, 0, 0);
    }
};
