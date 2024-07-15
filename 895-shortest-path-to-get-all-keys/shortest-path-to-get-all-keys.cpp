class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        queue<vector<int>>q;

        int str=-1,stc=-1;
        int nkey=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='@'){
                    str=i;
                    stc=j;
                }else if(grid[i][j]>='a' && grid[i][j]<='f'){
                    nkey++;
                }
            }
        }

        vector<vector<vector<int>>>vis(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(1<<nkey,0)));

        q.push({str,stc,0,0});
        vis[str][stc][0]=1;

        vector<int>mk(8,0);

        vector<int>dr={0,0,-1,1};
        vector<int>dc={1,-1,0,0};
        while(!q.empty()){
            int r=q.front()[0];
            int c=q.front()[1];
            int lvl=q.front()[2];
            int key=q.front()[3];
            q.pop();

          
           
            if(key==(1<<nkey)-1){
                return lvl;
           }
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

               if(nr>=0 && nc>=0&& nr<grid.size() && nc<grid[0].size() && grid[nr][nc]!='#' ){
                   int newKey = key;

                    if (grid[nr][nc] >= 'a' && grid[nr][nc] <= 'f') {
                        newKey |= 1 << (grid[nr][nc] - 'a');
                    }

                    if (vis[nr][nc][newKey] == 1) {
                        continue;
                    }

                    if (grid[nr][nc] >= 'A' && grid[nr][nc] <= 'F' && !(newKey & (1 << (grid[nr][nc] - 'A')))) {
                        continue;
                    }

                    vis[nr][nc][newKey] = 1;
                    q.push({nr, nc, lvl + 1, newKey});
                }
            }
        }
        return -1;
    }
};