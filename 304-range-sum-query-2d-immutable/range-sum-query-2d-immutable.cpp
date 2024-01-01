class NumMatrix {
public:
    vector<vector<int>>pre;
    vector<vector<int>>mat;
    NumMatrix(vector<vector<int>>& matrix) {
        mat=matrix;
        int n=matrix.size();
        int m=matrix[0].size();
        pre.resize(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=matrix[i][j];
                if(i-1>=0){
                    sum+=pre[i-1][j];
                }
                if(j-1>=0){
                    sum+=pre[i][j-1];
                }
                if(i-1>=0 && j-1>=0){
                    sum-=pre[i-1][j-1];
                }
                pre[i][j]=sum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
      
       int ans=pre[row2][col2];
       if(col1-1>=0){
           ans-=pre[row2][col1-1];
       }
       if(row1-1>=0){
           ans-=pre[row1-1][col2];
       }
       if(row1-1>=0 && col1-1>=0){
           ans+=pre[row1-1][col1-1];
       }
       return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */