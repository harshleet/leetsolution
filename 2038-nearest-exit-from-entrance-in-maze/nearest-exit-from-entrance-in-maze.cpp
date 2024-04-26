class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<tuple<int,int,int>>q;
        q.push({entrance[0],entrance[1],0});
        int n=maze.size(),m=maze[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[entrance[0]][entrance[1]]=1;

        vector<int>dr={1,-1,0,0};
        vector<int>dc={0,0,-1,1};

        while(!q.empty()){
            int r=get<0>(q.front());
            int c=get<1>(q.front());
            int lvl=get<2>(q.front());
            q.pop();
          

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && maze[nr][nc]=='.'){
                    cout<<nr<<" "<<nc<<endl;
                    vis[nr][nc]=1;
                    q.push({nr,nc,lvl+1});
                }else if((nr<0 || nc<0 || nr>=n || nc>=m) && (r!=entrance[0] || c!=entrance[1]) ){
                    return lvl;
                }               
            }

        }
        return -1;

    }
};