class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<tuple<int,int,int>>q;
        if(grid[0][0]==1){
             return -1;
        }
       vector<vector<int>>vis(n,vector<int>(n,0));
        q.push({0,0,0});
        vis[0][0]=1;
       int dr[]={0,0,1,1,1,-1,-1,-1};
       int dc[]={-1,1,0,1,-1,0,1,-1};
        while(!q.empty()){
            int row=get<0>(q.front());
            int col=get<1>(q.front());
            int step=get<2>(q.front());
            
            q.pop();

            if(row==n-1 && col==n-1){
                return step+1;
            }
            for(int i=0;i<8;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow<n && ncol<n && nrow>=0 && ncol>=0 && grid[nrow][ncol]==0 && !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol,step+1});
                }
            }
        
        }
        return -1;
    }
};