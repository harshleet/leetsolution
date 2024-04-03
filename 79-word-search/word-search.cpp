class Solution {
public:
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};
    bool helper(int r, int c, string ds, vector<vector<char>>& board,
                string word, vector<vector<int>>& vis,int ind) {
        vis[r][c] = 1;
        if (ds.size() == word.size()) {
            cout<<ds<<" ";
            return ds == word;
        }
        bool ans = false;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < board.size() &&
                nc < board[0].size() && !vis[nr][nc] && word[ind]==board[nr][nc]) {
                ds.push_back(board[nr][nc]);
                ans|=helper(nr, nc, ds, board, word, vis,ind+1);
                ds.pop_back();
            }
        }
        vis[r][c] = 0;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        int n = board.size(), m = board[0].size();
         string ds="";
         vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
              if(word[0]==board[i][j]){
                ds.push_back(board[i][j]);
                ans |= helper(i, j,ds, board, word, vis,1);
                 ds.pop_back();}
            }
        }
        return ans;
    }
};