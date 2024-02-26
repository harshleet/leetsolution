class Solution {
public:
vector<int>drow={-1,1,0,0};
vector<int>dcol={0,0,-1,1};

    void dfs(int row,int col,vector<vector<char>>& board,vector<vector<int>>&vis){
        
        if(row<0 || col<0 || row>=board.size()|| col>=board[0].size()){
            return;
        }
        if(vis[row][col]==1 || board[row][col]=='X'){
              return;
        }
        vis[row][col]=1;
       
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            dfs(nrow,ncol,board,vis);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
      
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,board,vis);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,board,vis);
            }
        }
        for(int j=0;j<m;j++){
             if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,board,vis);
            }
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,board,vis);
            }
        }
        for(int i=0;i<n;i++){
             for(int j=0;j<m;j++){
                 if(vis[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
             }
            
          
        }
                 
    }
};