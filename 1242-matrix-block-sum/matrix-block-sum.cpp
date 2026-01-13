class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>>pre(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                pre[i][j+1]=pre[i][j]+mat[i-1][j];
            }
        } 
        // for(int i=0;i<n+1;i++){
        //     for(int j=0;j<m+1;j++){
        //         cout<<pre[i][j]<<" ";
        //     }
        //     cout<<endl;
        // } 
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n;j++){
                pre[j+1][i]+=pre[j][i];
            }
        }
        // for(int i=0;i<n+1;i++){
        //     for(int j=0;j<m+1;j++){
        //         cout<<pre[i][j]<<" ";
        //     }
        //     cout<<endl;
        // } 
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int sum=0;
                int minc=max(0,j-k),maxc=min(m-1,j+k),minr=max(0,i-k),maxr=min(n-1,i+k);  
                sum=pre[maxr+1][maxc+1]-pre[maxr+1][minc]-pre[minr][maxc+1]+pre[minr][minc];
                ans[i][j]=sum;
            }
        } 
        return ans;
    }
};