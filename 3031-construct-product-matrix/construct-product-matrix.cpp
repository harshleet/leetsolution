class Solution {
public:
int mod=12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<long long int>left((n*m)+1);
        vector<long long int>right((n*m)+1);
       
          left[0]=1;
          right[n*m]=1;
          for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    left[i*m+j+1]=(left[i*m+j]*grid[i][j])%mod;
                    
                }  
          }
          for(int i=n-1;i>=0;i--){
                for(int j=m-1;j>=0;j--){
                    right[i*m+j]=(right[i*m+j+1]*grid[i][j])%mod;
                }  
          }
          vector<vector<int>>ans(n,vector<int>(m));
          for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                   ans[i][j]=(left[i*m+j]*right[i*m+j+1])%mod;
                }  
          }
        return ans;
    }
};