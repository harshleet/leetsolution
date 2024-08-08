class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
          int n=rows,m=cols;
          
          int cnt=0;
          vector<vector<int>>v;

          int step=0,dir=0;
           int r=rStart,c=cStart;

          vector<int>dr={0,1,0,-1};
          vector<int>dc={1,0,-1,0};
          int tc=1;
          v.push_back({r,c});
          while(tc<m*n){
            if(dir==0 || dir==2){
                step++;
            }
            for(int i=0;i<step;i++){
                r=r+dr[dir];
                c=c+dc[dir];
                if(r>=0 && c>=0 && r<n && c<m){
                    v.push_back({r,c});
                    tc++;
                }
            }
            dir=(dir+1)%4;
          }
          return v;
    }
};