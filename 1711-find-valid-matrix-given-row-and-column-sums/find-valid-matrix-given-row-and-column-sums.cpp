class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n=rowSum.size(),m=colSum.size();
        vector<vector<int>>v(n,vector<int>(m));

        for(int i=0;i<m;i++){
            int col=colSum[i];
           for(int j=0;j<n;j++){
            int mini=min(col,rowSum[j]);
             v[j][i]=mini;
             col-=mini;
             rowSum[j]-=mini;
           }
        }
        return v;
    }
};