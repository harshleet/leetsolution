class Solution {
public:
   
    // int drow[4] = {1, -1, 0, 0};
    // int dcol[4] = {0, 0, 1, -1};
    int n = 3;

    // void dfs(int ro, int co, vector<vector<int>>& grid, vector<vector<int>>& vis, queue<pair<pair<int, int>, int>>& q) {
    //     q.push({{ro, co}, 0});
    //     vis[ro][co] = 1;
    //     int mini=INT_MAX;
    //     int r=0;
    //     int c=0;
    //     while (!q.empty()) {
    //         int row = q.front().first.first;
    //         int col = q.front().first.second;
    //         int step = q.front().second;
    //         q.pop();
    //         if (grid[row][col] > 1) {
             
    //            if(step<mini){
    //                r=row;
    //                c=col;
    //             mini=min(mini,step);
    //            }
               
    //         }

    //         for (int i = 0; i < 4; i++) {
    //             int nrow = row + drow[i];
    //             int ncol = col + dcol[i];
    //             if (nrow < n && ncol < n && nrow >= 0 && ncol >= 0 && !vis[nrow][ncol]) {
    //                 q.push({{nrow, ncol}, step + 1});
    //                 vis[nrow][ncol] = 1;
    //             }
    //         }
    //     }
    //     grid[r][c]--;
    //     cnt+=mini;
    // }
    int number(vector<vector<int>>& grid){
        int cnt=0;
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j]==0)
                 cnt++;
            }
          }
          return cnt;
    }
    int minimumMoves(vector<vector<int>>& grid) {
       int no=number(grid);
       if(no==0){
           return 0;
       }
       int mini=INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                   
                    for(int k=0;k<n;k++){
                        for(int l=0;l<n;l++){
                              int cnt = abs(k-i)+abs(l-j);;
                            if(grid[k][l]>1){
                                grid[k][l]--;
                                grid[i][j]++;
                                mini=min(mini,cnt+minimumMoves(grid));
                                grid[k][l]++;
                                grid[i][j]--;
                            }
                        }
                    }
                }
               
            }
        }

        return mini;
    }
};
