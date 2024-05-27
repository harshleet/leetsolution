class Solution {
public:
    int mod = 1e9 + 7;
    int helper(int to, int ab, int la, int n, vector<vector<vector<int>>>& dp) {
        // if(ab>=2 || la>=3){
        //     return 0;
        // }
        if (to >= n) {
            return 1;
        }
        if (dp[to][la][ab] != -1) {
            return dp[to][la][ab];
        }
        long long ans =0;
        ans= (ans+helper(to + 1, ab, 0, n, dp))%mod;
        if (la < 2) {
            ans =(ans+ helper(to + 1, ab, la + 1, n, dp))%mod;
        }
        if (ab < 1) {
            ans =(ans+  helper(to + 1, ab + 1, 0, n, dp))%mod;
        }
        return dp[to][la][ab] = ans%mod;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(3, vector<int>(2, -1)));
        return helper(0, 0, 0, n, dp);
    }
};