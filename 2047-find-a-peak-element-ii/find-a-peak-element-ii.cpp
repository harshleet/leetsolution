class Solution {
public:
   int max_row(int mid,vector<vector<int>>& mat){
    int maxi=0,maxii=0;

    for(int i=0;i<mat.size();i++){
        if(maxi<mat[i][mid]){
            maxi=mat[i][mid];
            maxii=i;
        }
    }
    return maxii;
   }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m=mat[0].size(),n=mat.size();
        int l=0,h=m-1;

        while(l<=h){
            int mid=(l+h)/2;

            int ind=max_row(mid,mat);
            if(mid>0 && mat[ind][mid-1]>mat[ind][mid]){
                h=mid-1;
            }else if(mid<m-1 && mat[ind][mid+1]>mat[ind][mid]){
                l=mid+1;
            }else{
                return {ind,mid};
            }
        }
        return {-1,-1};
    }
};