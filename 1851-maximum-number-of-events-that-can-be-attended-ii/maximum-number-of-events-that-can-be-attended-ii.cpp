class Solution {
public:
    int helper(vector<vector<int>>& dp, int ind, int l_time, vector<vector<int>>& events, int k) {
        if (ind >= events.size() || k == 0) {
            return 0;
        }
        if (dp[ind][k] != -1) {
            return dp[ind][k];
        }

        int ntake = helper(dp, ind + 1, l_time, events, k);
          int i;
        for(i = ind + 1; i < events.size(); i++){
            if(events[i][0] > events[ind][1])
                break;
        
        }
        int take = events[ind][2] + helper(dp,i,l_time, events, k-1);
        return dp[ind][k] = max(take, ntake);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size(), vector<int>(k + 1, -1));
        return helper(dp, 0, -1000, events, k);
    }
};
