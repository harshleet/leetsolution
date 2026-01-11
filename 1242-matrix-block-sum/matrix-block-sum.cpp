class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>pre(n,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pre[i][j+1]=pre[i][j]+mat[i][j];
            }
        } 
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=0;
                for(int f=max(0,i-k);f<=min(n-1,i+k);f++){
                    int minc=max(0,j-k),maxc=min(m-1,j+k);
                    sum+=pre[f][maxc+1]-pre[f][minc];
                }
                ans[i][j]=sum;
            }
        } 
        return ans;
    }
};