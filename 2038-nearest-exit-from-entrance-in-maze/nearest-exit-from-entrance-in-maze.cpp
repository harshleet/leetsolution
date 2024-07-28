class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {

        int n=maze.size();
        int m=maze[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        queue<vector<int>>q;
        q.push({entrance[0],entrance[1],0});
        dist[entrance[0]][entrance[1]]=0;

        vector<int>dr={1,-1,0,0};
        vector<int>dc={0,0,1,-1};
        while(!q.empty()){
            vector<int>v=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nr=v[0]+dr[i];
                int nc=v[1]+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && maze[nr][nc]=='.' && v[2]+1<dist[nr][nc]){
                    dist[nr][nc]=1+v[2];
                    q.push({nr,nc,dist[nr][nc]});
                }
            }
        }
        int mini=1e9;
        for(int i=0;i<n;i++){
            if(i!=entrance[0] || entrance[1]!=0)
                 mini=min(mini,dist[i][0]);
        }
        for(int i=0;i<m;i++){
            if(entrance[0]!=0 || entrance[1]!=i)
                  mini=min(mini,dist[0][i]);
        }
        for(int i=0;i<n;i++){
            if(i!=entrance[0] || entrance[1]!=m-1)
                  mini=min(mini,dist[i][m-1]);
        }
        for(int i=0;i<m;i++){
            if(entrance[0]!=n-1 || entrance[1]!=i)
                mini=min(mini,dist[n-1][i]);
        }
        if(mini==1e9){
            return -1;
        }
        return mini;
    }
};