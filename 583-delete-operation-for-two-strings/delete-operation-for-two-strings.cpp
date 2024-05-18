class Solution {
public:
    int helper(int ind1, int ind2, string& s1, string& s2,
               vector<vector<int>>& dp) {
        if (ind1 >= s1.size() || ind2 >= s2.size()) {
            return 0;
        }
        if (dp[ind1][ind2] != -1) {
            return dp[ind1][ind2];
        }
        int in1 = helper(ind1 + 1, ind2, s1, s2, dp);
        int in2 = helper(ind1, ind2 + 1, s1, s2, dp);
        int nin = 0;
        if (s1[ind1] == s2[ind2]) {
            nin = 1 + helper(ind1 + 1, ind2 + 1, s1, s2, dp);
        }
        return dp[ind1][ind2] = max({in1, in2, nin});
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        return word1.size()+word2.size()-2*helper(0, 0, word1, word2, dp);
    }
};