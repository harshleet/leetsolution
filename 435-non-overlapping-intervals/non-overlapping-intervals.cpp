class Solution {
public:
    int findNextNonOverlapping(vector<vector<int>>& intervals, int target, int ind) {
        int left = ind + 1;
        int right = intervals.size() - 1;
        int res = intervals.size();
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (intervals[mid][0] >= target) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return res;
    }

    int helper(vector<vector<int>>& intervals, int ind, vector<int>& dp) {
        if (ind >= intervals.size()) {
            return 0;
        }
        if (dp[ind] != -1) {
            return dp[ind];
        }

        int ntake = helper(intervals, ind + 1, dp);

        int nextNonOverlapping = findNextNonOverlapping(intervals, intervals[ind][1], ind);
        int take = 0;
        if (nextNonOverlapping < intervals.size() && intervals[ind][1] <= intervals[nextNonOverlapping][0]) {
            take = 1 + helper(intervals, nextNonOverlapping, dp);
        }

        return dp[ind] = max(take, ntake);
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        vector<int> dp(n, -1);
        int val = helper(intervals, 0, dp);
        return n - val-1;
    }
};
