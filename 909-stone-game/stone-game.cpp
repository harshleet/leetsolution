#include <vector>
#include <numeric>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, unordered_map<int, unordered_map<int, bool>>> dp;

    bool helper(int ind1, int ind2, vector<int>& piles, int st1, int st2, int t) {
        if (ind1 > ind2) {
            return st1 > st2;
        }
        if (dp[ind1].count(ind2) && dp[ind1][ind2].count(t)) {
            return dp[ind1][ind2][t];
        }
        if (t == 1) {
            dp[ind1][ind2][t] = helper(ind1 + 1, ind2, piles, st1 + piles[ind1], st2, 0) ||
                                helper(ind1, ind2 - 1, piles, st1 + piles[ind2], st2, 0);
        } else {
            dp[ind1][ind2][t] = helper(ind1 + 1, ind2, piles, st1, st2 + piles[ind1], 1) ||
                                helper(ind1, ind2 - 1, piles, st1, st2 + piles[ind2], 1);
        }
        return dp[ind1][ind2][t];
    }

    bool stoneGame(vector<int>& piles) {
        int a = accumulate(piles.begin(), piles.end(), 0);
        return helper(0, piles.size() - 1, piles, 0, 0, 1);
    }
};
