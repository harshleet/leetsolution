class Solution {
public:
    bool helper(int sum, int bitmask, int tar, int cnt, vector<int>& matchsticks, vector<int>& dp) {
        if (cnt == 4) {
            return true;
        }
        if (dp[bitmask] != -1) {
            return dp[bitmask];
        }
        if (sum == tar) {
            return dp[bitmask] = helper(0, bitmask, tar, cnt + 1, matchsticks, dp);
        }
        
        bool ans = false;
        for (int i = 0; i < matchsticks.size(); i++) {
            if ((bitmask & (1 << i)) == 0 && sum + matchsticks[i] <= tar) {
                int temp = bitmask;
                temp |= (1 << i);
                ans = helper(sum + matchsticks[i], temp, tar, cnt, matchsticks, dp);
                if (ans) break;  // Early exit if true
            }
        }
        
        return dp[bitmask] = ans;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        int maxi = *max_element(matchsticks.begin(), matchsticks.end());
        if (sum % 4 != 0) {
            return false;
        }
        if (sum / 4 < maxi) {
            return false;
        }

        int n = matchsticks.size();
        vector<int> dp(1 << n, -1);
        return helper(0, 0, sum / 4, 0, matchsticks, dp);
    }
};
