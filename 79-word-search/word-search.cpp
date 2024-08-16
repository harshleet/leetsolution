class Solution {
public:
    vector<int>dr={1,-1,0,0};
    vector<int>dc={0,0,-1,1};
    bool helper(int r,int c,int ind,string& word,vector<vector<char>>&board,int n,int m,vector<vector<int>>&vis){
        if(ind==word.size()){
            return true;
        }
        vis[r][c]=1;
        bool ans=false;
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr>=0 && nc>=0 && nr<n && nc<m && board[nr][nc]==word[ind] && !vis[nr][nc]){
                if(ind==word.size()-1){
                    return true;
                }
                ans=ans|helper(nr,nc,ind+1,word,board,n,m,vis);
            }
        }
        vis[r][c]=0;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        bool ans=false;
         vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                   
                    ans=ans|helper(i,j,1,word,board,n,m,vis);
                }
            }
        }
        return ans;
    }
};