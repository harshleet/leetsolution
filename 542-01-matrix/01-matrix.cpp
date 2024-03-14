class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<tuple<int,int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                     ans[i][j]=0;
                  vis[i][j]=1;
                   q.push({i,j,0});
                }
              
            }
        }
        vector<int>dr={1,-1,0,0};
        vector<int>dc={0,0,-1,1};
        while(!q.empty()){
            int r=get<0>(q.front());
            int c=get<1>(q.front());
            int dis=get<2>(q.front());
            q.pop();
            ans[r][c]=dis;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m &&!vis[nr][nc] ){
                    vis[nr][nc]=1;
                    q.push({nr,nc,dis+1});
                }
            }

        }
        return ans;
    }
};