class Solution {
public:
    bool search(int row,vector<vector<int>>&matrix,int target){
        int l=0,h=matrix[0].size()-1;

        while(l<=h){
            int mid=(l+h)/2;
            if(target==matrix[row][mid]){
                return true;
            }else if(target<matrix[row][mid]){
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,h=matrix.size()-1;
        int n=matrix.size(),m=matrix[0].size();
        while(l<=h){
            int mid=(l+h)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid].back()){
                return search(mid,matrix,target);
            }else if(target<matrix[mid][0]){
                h=mid-1;
            }else if(target>matrix[mid].back()){
                l=mid+1;
            }
        }
        return false;
    }
};