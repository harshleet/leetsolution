class Solution {
public:
     vector<int>dr={0,0,-1,1};
     vector<int>dc={-1,1,0,0};
    bool helper(int row,int col,string ds,vector<vector<char>>& board, string word,vector<vector<int>>&vis,int ind){
        vis[row][col]=1;
        if(ds.size()==word.size()){
          
            if(ds==word){
                return true;
            }
            return false;
        }
        bool ans=false;
        for(int i=0;i<4;i++){
            int nrow=row+dr[i];
            int ncol=col+dc[i];
            if(nrow<board.size() && ncol<board[0].size() && nrow>=0 && ncol>=0 && !vis[nrow][ncol] && word[ind]==board[nrow][ncol]){
              
                ds.push_back(board[nrow][ncol]);
                ans|=helper(nrow,ncol,ds,board,word,vis,ind+1);
                ds.pop_back();
              
            }
        }
          vis[row][col]=0;
        return ans;

    }
    bool exist(vector<vector<char>>& board, string word) {
        string ds="";
        bool ans=false;
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
               if(word[0]==board[i][j]){ 
               
                 ds.push_back(board[i][j]);

                  ans|=helper(i,j,ds,board,word,vis,1);
                  ds.pop_back();
                }
            }
        }
       return ans;

    }
};