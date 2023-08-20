class Solution {
public:
    int helper(int ind, int sold, vector<int>& dp, vector<vector<int>>& offers) {
        if (ind == offers.size()) {
            return 0;
        }
        if (dp[ind] != -1) {
            return dp[ind];
        }
        int ntake = helper(ind + 1, sold, dp, offers);

        int low = ind + 1, high = offers.size() - 1;
        int next_idx = offers.size();

        while (low <= high) {
            int mid = (low + high) / 2;
            if (offers[mid][0] > offers[ind][1]) {
                high = mid - 1;
                next_idx = mid;
            } else {
                low = mid + 1;
            }
        }

        int take = offers[ind][2] + helper(next_idx, sold, dp, offers); // Changed 'solve' to 'helper'

        return dp[ind] = max(take, ntake);
    }

    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        vector<int> dp(offers.size(), -1);
        sort(offers.begin(), offers.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        return helper(0, -1, dp, offers);
    }
};
