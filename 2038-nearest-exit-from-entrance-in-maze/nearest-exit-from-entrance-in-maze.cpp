class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<vector<int>>q;

        q.push({entrance[0],entrance[1],0});

        vector<int>dr={1,-1,0,0};
        vector<int>dc={0,0,-1,1};

        int n=maze.size(),m=maze[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[entrance[0]][entrance[1]]=1;

        while(!q.empty()){

            int r=q.front()[0];
            int c=q.front()[1];
            int dist=q.front()[2];
            q.pop();

            if((r==n-1 || r==0|| c==0|| c==m-1) && (r!=entrance[0] || c!=entrance[1])){
                return dist;
            }

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && maze[nr][nc]=='.'){
                    vis[nr][nc]=1;
                    q.push({nr,nc,dist+1});
                }
            }
        }
        return -1;

    }
};