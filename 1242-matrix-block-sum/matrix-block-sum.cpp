#include <vector>

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int val = 0;
                for (int x = max(0, i - k); x <= min(n - 1, i + k); x++) {
                    for (int y = max(0, j - k); y <= min(m - 1, j + k); y++) {
                        val += mat[x][y];
                    }
                }
                ans[i][j] = val;
            }
        }
        return ans;
    }
};
