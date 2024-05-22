class Solution {
public:
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};
    bool helper(int r, int c, vector<vector<char>>& board, string word,
                int ind,vector<vector<int>>&vis) {
        if (ind >= word.size()) {
            return true;
        }
        vis[r][c]=1;
        bool fl = false;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < board.size() && nc < board[0].size() && nr >= 0 && nc >= 0 && board[nr][nc] == word[ind] && !vis[nr][nc]) {
                // cout<<nr<<" "<<nc<<" ";
                fl = fl || helper(nr, nc, board, word, ind + 1,vis);
            }
        }
        vis[r][c]=0;
        return fl;
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        bool f = false;
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),0));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    f = f || helper(i, j, board, word, 1,vis);
                }
            }
        }
        return f;
    }
};