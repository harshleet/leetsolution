class Solution {
public:
    int search(int vl, vector<vector<int>>& intervals, int ind) {
        int low = ind, high = intervals.size() - 1, ans = intervals.size();
        while (low <= high) {
            int mid = (low + high) / 2;

            if (intervals[mid][0] >= vl) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    int helper(int ind, int last, vector<vector<int>>& intervals,
               vector<int>& dp) {
        if (ind >= intervals.size()) {
            return 0;
        }
        if (dp[ind] != -1) {
            return dp[ind];
        }
        int nt = helper(ind + 1, last, intervals, dp);
        int f = search(intervals[ind][1], intervals, ind + 1);
        cout << intervals[ind][1] << " " << f << endl;
        int t = 1+helper(f, intervals[ind][1], intervals, dp);

        return dp[ind] = max(t, nt);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> temp(intervals.size());
        // for (int i = 0; i < temp.size(); i++) {
        //     temp[i] = {intervals[i][0], intervals[i][1]};
        // }
        vector<int> dp(intervals.size(), -1);

        return intervals.size()-helper(0, INT_MIN, intervals, dp);
    }
};