class Solution {
public:
    void helper(std::vector<std::vector<std::string>>& ans, std::vector<std::string>& board, int n, int ind, std::vector<int>& r, std::vector<int>& ld, std::vector<int>& rd) {
        if (ind >= n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (r[row] == 0 && ld[ind + row] == 0 && rd[n - 1 - row + ind] == 0) {
                r[row] = 1;
                ld[ind + row] = 1;
                rd[n - 1 - row + ind] = 1;
                board[ind][row] = 'Q';
                helper(ans, board, n, ind + 1, r, ld, rd);
                board[ind][row] = '.';
                r[row] = 0;
                ld[ind + row] = 0;
                rd[n - 1 - row + ind] = 0;
            }
        }
    }

    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<int> r(n, 0);
        std::vector<int> ld(2 * n, 0);
        std::vector<int> rd(2 * n, 0);
        std::vector<std::string> board(n, std::string(n, '.'));

        std::vector<std::vector<std::string>> ans;
        helper(ans, board, n, 0, r, ld, rd);

        return ans;
    }
};