class Solution {
public:
    vector<int> dr1 = {1, 1, 0, 0};
    vector<int> dc1 = {0, 0, 1, 1};
    vector<int> dr2 = {1, 0, 0, 1};
    vector<int> dc2 = {0, 1, 1, 0};
    int helper(int r1, int c1, int r2, int c2, vector<vector<int>>& grid, int n,
               int m, vector<vector<vector<vector<int>>>> & dp) {
        if (r1 == n - 1 && c1 == m - 1) {
            int val = grid[r1][c1];
         
            return val;
        }
        if (r2 == n - 1 && c2 == m - 1) {
            int val = grid[r2][c2];
    
            return val;
        }
        if(dp[r1][c1][r2][c2]!=-1){
            return dp[r1][c1][r2][c2];
        }
        int ch = 0;
        if (r1 == r2 && c1 == c2) {
            ch = grid[r1][c1];
        } else {
            ch = grid[r1][c1] + grid[r2][c2];
        }
        int ans = INT_MIN;
        for (int i = 0; i < 4; i++) {
            int nr1 = r1 + dr1[i];
            int nc1 = c1 + dc1[i];
            int nr2 = r2 + dr2[i];
            int nc2 = c2 + dc2[i];
            if (nr1 >= 0 && nc1 >= 0 && nr1 < n && nc1 < m &&
                grid[nr1][nc1] != -1 && nr2 >= 0 && nc2 >= 0 && nr2 < n &&
                nc2 < m && grid[nr2][nc2] != -1) {
                ans = max(ans, helper(nr1, nc1, nr2, nc2, grid, n, m, dp));
            }
        }
        return dp[r1][c1][r2][c2]=ch + ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        // try this using to times dp
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<vector<int>>>> dp(
            n, vector<vector<vector<int>>>(
                   m, vector<vector<int>>(n, vector<int>(m, -1))));
        vector<vector<int>> dp2(n, vector<int>(m, -1));
        int val = helper(0, 0, 0, 0, grid, n, m, dp);
        if (val < 0) {
            return 0;
        }
        return val;
    }
};