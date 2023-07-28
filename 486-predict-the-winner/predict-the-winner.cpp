class Solution {
public:
    int helper(vector<int>& nums, vector<vector<vector<int>>>& dp, int turn, int start, int end, int sc1, int sc2) {
        if (start > end) {
            return 0;
        }

        if (dp[start][end][turn] != -1) {
            return dp[start][end][turn];
        }

        int ts =0,tl=0; 

        if (turn == 0) {
            ts=nums[start] + helper(nums, dp, !turn, start + 1, end, sc2, sc1 + nums[start]);
            tl=    nums[end] + helper(nums, dp, !turn, start, end - 1, sc2, sc1 + nums[end]);

            return dp[start][end][turn] = max(ts, tl);
        } else {
             ts=-nums[start] + helper(nums, dp, !turn, start + 1, end, sc2 + nums[start], sc1);
              tl=-nums[end] + helper(nums, dp, !turn, start, end - 1, sc2+ nums[end], sc1 );
            return dp[start][end][turn] = min(ts, tl);
        }

    }

    bool PredictTheWinner(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(nums.size(), vector<int>(2, -1)));
        int a = helper(nums, dp, 0, 0, nums.size() - 1, 0, 0);
        if (a >= 0) {
            return true;
        }
        return false;
    }
};
