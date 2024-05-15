class Solution {
public:
    vector<int>dr={1,0,-1,0};
    vector<int>dc={0,1,0,-1};

   
    bool dfs(int r,int c,int mini,int n,int m,vector<vector<int>>&man, vector<vector<int>>&vi){
        if(man[r][c]<mini){
            return false;
        }
        if(r==n-1 && c==m-1){
            return true;
        }
        vi[r][c]=1;
        bool a=false;
          for(int i=0;i<4;i++){
              int nrow=r+dr[i];
             int ncol=c+dc[i];
              if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vi[nrow][ncol] ){
                        a=a||dfs(nrow,ncol,mini,n,m,man,vi);
              }
          }
          
          return a;
           
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>man(n,vector<int>(m,0));
         vector<vector<int>>vis(n,vector<int>(m,0));
        queue<tuple<int,int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    vis[i][j]=1;
                     q.push({i,j,0});
                }
                
            }
        }

        
       
        while(!q.empty()){
                int r=get<0>(q.front());
                int c=get<1>(q.front());
                int step=get<2>(q.front());
                
                q.pop();
                man[r][c]=step;
                for(int i=0;i<4;i++){
                    int nrow=r+dr[i];
                    int ncol=c+dc[i];
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && vis[nrow][ncol]==0){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol,step+1});
                    }
                }
   
        }
        //now check for paths
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<man[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
         
         int low=0,high=min(man[0][0],man[n-1][m-1]);
         int ans=0;
         while(low<=high){
            int mid=(low+high)/2;
            vector<vector<int>>vi(n,vector<int>(m,0));
             if(dfs(0,0,mid,n,m,man,vi)){
                ans=mid;
                low=mid+1;
             }else{
                high=mid-1;
             }
         }
          
        return ans;
    }
};