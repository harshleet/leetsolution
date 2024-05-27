class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
       
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                vis[i][0]=1;
               q.push({i,0});
            }
            if(board[i][m-1]=='O'){
                vis[i][m-1]=1;
               q.push({i,m-1});
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                vis[0][i]=1;
               q.push({0,i});
            }
            if(board[n-1][i]=='O'){
                
                vis[n-1][i]=1;
               q.push({n-1,i});
            }
        }
        vector<int>dr={1,-1,0,0};
        vector<int>dc={0,0,-1,1};

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            // cout<<r<<" "<<c<<endl;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && board[nr][nc]=='O'){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                     board[i][j]='X';
                }
            }
        }
        // return board;
    }
};