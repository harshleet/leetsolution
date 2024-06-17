class Solution {
public:
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};
    void dfs(int r, int c, vector<vector<int>>& vis,
            map<int, vector<pair<int, int>>>& mp, int is,
            vector<vector<int>>& grid) {
        vis[r][c] = 1;
        mp[is].push_back({r,c});
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nc >= 0 && nr < grid.size() && nc<grid[0].size()&& !vis[nr][nc] && grid[nr][nc]==1){
                dfs(nr,nc,vis,mp,is,grid);
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        map<int, vector<pair<int, int>>> mp;
        vector<vector<int>> vis(n, vector<int>(m, 0));
         int is = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    dfs(i, j, vis, mp, is, grid);
                    is++;
                }
            }
        }
        vector<pair<int, int>>v1=mp[0];
        vector<pair<int, int>>v2=mp[1];
        int mini=INT_MAX;
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v2.size();j++){
                mini=min(mini,abs(v1[i].first-v2[j].first)+abs(v1[i].second-v2[j].second));
                // cout<<v1[i].first<<" "<<v1[i].second<<" "<<v2[j].first<<" "<<v2[j].second<<endl;
            }
        }
        return mini-1;
    }
};